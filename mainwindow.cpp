#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "device_data.h"
#include "csvexporter.h"
#include "datagenerator.h"
#include "alarmhighlightdelegate.h"

#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QAbstractItemView>
#include <QPushButton>
#include <QHeaderView>
#include <QTableView>
#include <QFileDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbManager()
    , tableModel(nullptr)
    , currentId(-1)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle("设备数据监控与历史管理系统");
    resize(1200, 800);

    initUi();
    applyStyle();
    initTimer();

    if(!dbManager.initDatabase()){
        QMessageBox::critical(this,"失败","数据库初始化失败!");
        return;
    }

    initTable();
    statusBar()->showMessage("系统就绪");

    connect(ui->addBtn,&QPushButton::clicked,this,&MainWindow::onAddClicked);
    connect(ui->tableView,&QTableView::clicked,this,&MainWindow::onTableClicked);
    connect(ui->deleteBtn,&QPushButton::clicked,this,&MainWindow::onDeleteClicked);
    connect(ui->clearBtn,&QPushButton::clicked,this,&MainWindow::clearInput);
    connect(ui->updateBtn,&QPushButton::clicked,this,&MainWindow::onUpdateClicked);

    connect(ui->searchBtn,&QPushButton::clicked,this,&MainWindow::onSearchClicked);
    connect(ui->showAllBtn,&QPushButton::clicked,this,&MainWindow::onShowAllClicked);
    connect(ui->exportBtn,&QPushButton::clicked,this,&MainWindow::onExportClicked);
    connect(ui->generateBtn,&QPushButton::clicked,this,&MainWindow::onGenerateClicked);
    connect(ui->startTimerBtn, &QPushButton::clicked, this, &MainWindow::onStartTimerClicked);
    connect(ui->stopTimerBtn, &QPushButton::clicked, this, &MainWindow::onStopTimerClicked);
}

MainWindow::~MainWindow()
{
    if (autoTimer && autoTimer->isActive()) {
        autoTimer->stop();
    }

    delete ui;
}

void MainWindow::initUi()
{
    //数据录入区
    ui->deviceNameEdit->setPlaceholderText("请输入设备名:");
    ui->updateBtn->setEnabled(false);
    ui->deleteBtn->setEnabled(false);
    ui->statusBox->addItems({"正常","报警","离线"});
    ui->tempSpinBox->setRange(-50.0,100.0);
    ui->tempSpinBox->setDecimals(1);
    ui->tempSpinBox->setSingleStep(0.5);
    ui->tempSpinBox->setValue(36.5);
    ui->tempSpinBox->setSuffix(" ℃");
    ui->humSpinBox->setRange(0,100);
    ui->humSpinBox->setValue(45);
    ui->humSpinBox->setSuffix(" %");

    //查询条件区
    ui->searchNameEdit->setPlaceholderText("按设备名查询:");
    ui->searchStatusBox->addItems({"全部","正常","报警","离线"});
    ui->minTempSpinBox->setRange(-50.0,100.0);
    ui->minTempSpinBox->setValue(-50.0);
    ui->minTempSpinBox->setDecimals(1);
    ui->minTempSpinBox->setSuffix(" ℃");
    ui->maxTempSpinBox->setRange(-50.0,100.0);
    ui->maxTempSpinBox->setValue(100.0);
    ui->maxTempSpinBox->setDecimals(1);
    ui->maxTempSpinBox->setSuffix(" ℃");
    ui->startTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->startTimeEdit->setCalendarPopup(true);
    ui->startTimeEdit->setDateTime(QDateTime::currentDateTime().addDays(-7));
    ui->endTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->endTimeEdit->setCalendarPopup(true);
    ui->endTimeEdit->setDateTime(QDateTime::currentDateTime());

    //实时模拟区
    ui->intervalSpinBox->setRange(500,10000);
    ui->intervalSpinBox->setSingleStep(500);
    ui->intervalSpinBox->setValue(1000);
    ui->intervalSpinBox->setSuffix(" ms");
    ui->startTimerBtn->setEnabled(true);
    ui->stopTimerBtn->setEnabled(false);

    //历史数据区
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setAlternatingRowColors(true);
}

void MainWindow::initTable()
{
    tableModel = dbManager.getDeviceDataModel(this);
    ui->tableView->setModel(tableModel);
    ui->tableView->setItemDelegate(new AlarmHighlightDelegate(ui->tableView));
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();

    updateStats();
}

void MainWindow::initTimer()
{
    autoTimer = new QTimer(this);

    connect(autoTimer, &QTimer::timeout, this, [this]() {
        generateOneData(false);
    });
}

void MainWindow::refreshTable()
{
    if(!tableModel){
        return;
    }

    tableModel->select();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    updateStats();
}

void MainWindow::applyStyle()
{
    QString style = R"(
        QMainWindow {
            background-color: #f5f7fa;
        }

        QGroupBox {
            font-size: 14px;
            font-weight: bold;
            border: 1px solid #dcdfe6;
            border-radius: 8px;
            margin-top: 12px;
            background-color: #ffffff;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            left: 12px;
            padding: 0 4px;
            color: #303133;
        }

        QLabel {
            font-size: 13px;
            color: #303133;
        }

        QLineEdit,
        QComboBox,
        QSpinBox,
        QDoubleSpinBox,
        QDateTimeEdit {
            min-height: 26px;
            border: 1px solid #dcdfe6;
            border-radius: 4px;
            padding: 2px 6px;
            background-color: #ffffff;
        }

        QLineEdit:focus,
        QComboBox:focus,
        QSpinBox:focus,
        QDoubleSpinBox:focus,
        QDateTimeEdit:focus {
            border: 1px solid #409eff;
        }

        QPushButton {
            min-height: 28px;
            border-radius: 4px;
            background-color: #409eff;
            color: white;
            padding: 4px 12px;
            font-size: 13px;
        }

        QPushButton:hover {
            background-color: #66b1ff;
        }

        QPushButton:pressed {
            background-color: #337ecc;
        }

        QPushButton:disabled {
            background-color: #c0c4cc;
            color: #ffffff;
        }

        QTableView {
            background-color: #ffffff;
            alternate-background-color: #f5f7fa;
            gridline-color: #ebeef5;
            selection-background-color: #409eff;
            selection-color: white;
            border: 1px solid #dcdfe6;
        }

        QHeaderView::section {
            background-color: #eef1f6;
            color: #303133;
            padding: 5px;
            border: 1px solid #dcdfe6;
            font-weight: bold;
        }

        QStatusBar {
            background-color: #ffffff;
            color: #606266;
        }
    )";

    this->setStyleSheet(style);
}

void MainWindow::onAddClicked()
{
    if(!checkInput()){
        return;
    }
    QString deviceName = ui->deviceNameEdit->text().trimmed();
    deviceData data;
    data.deviceName = deviceName;
    data.temperature = ui->tempSpinBox->value();
    data.humidity = ui->humSpinBox->value();
    data.status = ui->statusBox->currentText();
    data.createdTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    bool ok = dbManager.insertData(data);
    if(!ok){
        QMessageBox::critical(this,"失败","数据插入失败!");
        statusBar()->showMessage("添加数据失败");
        return;
    }

    refreshTable();
    clearInput();
    if (data.temperature >= 38.0) {
        statusBar()->showMessage("添加成功，触发温度报警：" + data.deviceName + "，温度：" + QString::number(data.temperature, 'f', 1) + " ℃", 5000
            );
    } else {
        statusBar()->showMessage("添加数据成功：" + data.deviceName, 3000);
    }
}

void MainWindow::onTableClicked(const QModelIndex &index)
{
    if(!index.isValid() || !tableModel){
        return;
    }

    int row = index.row();
    currentId = tableModel->data(tableModel->index(row,0)).toInt();
    QString device_name = tableModel->data(tableModel->index(row,1)).toString();
    double temp = tableModel->data(tableModel->index(row,2)).toDouble();
    int hum = tableModel->data(tableModel->index(row,3)).toInt();
    QString status = tableModel->data(tableModel->index(row,4)).toString();

    ui->deviceNameEdit->setText(device_name);
    ui->tempSpinBox->setValue(temp);
    ui->humSpinBox->setValue(hum);
    int status_ID = ui->statusBox->findText(status);
    if(status_ID>=0){
        ui->statusBox->setCurrentIndex(status_ID);
    }

    ui->updateBtn->setEnabled(true);
    ui->deleteBtn->setEnabled(true);

    statusBar()->showMessage("已选中数据 ID: "+QString::number(currentId),3000);
}

void MainWindow::onDeleteClicked()
{
    if(currentId<0){
        QMessageBox::warning(this,"错误","请选择要删除的数据!");
        return;
    }

    int ret = QMessageBox::question(this,"确认","你确定要删除该数据吗?",QMessageBox::Yes | QMessageBox::No);
    if(ret != QMessageBox::Yes){
        statusBar()->showMessage("已取消删除!", 3000);
        return;
    }

    bool ok = dbManager.deleteData(currentId);
    if(!ok){
        QMessageBox::critical(this,"失败","删除数据失败!");
        statusBar()->showMessage("数据删除失败!",3000);
        return;
    }

    refreshTable();
    clearInput();
    statusBar()->showMessage("数据已删除!",3000);
}

void MainWindow::clearInput()
{
    currentId = -1;

    ui->deviceNameEdit->clear();
    ui->tempSpinBox->setValue(36.5);
    ui->humSpinBox->setValue(45);
    ui->statusBox->setCurrentIndex(0);

    ui->tableView->clearSelection();

    ui->updateBtn->setEnabled(false);
    ui->deleteBtn->setEnabled(false);

    ui->deviceNameEdit->setFocus();

    statusBar()->showMessage("输入已清空!",3000);
}

void MainWindow::onUpdateClicked()
{
    if(currentId==-1){
        QMessageBox::warning(this, "错误", "请选择要修改的数据!");
        return;
    }

    if(!checkInput()){
        return;
    }

    QString device_name = ui->deviceNameEdit->text().trimmed();
    deviceData data;
    data.id = currentId;
    data.deviceName = device_name;
    data.temperature = ui->tempSpinBox->value();
    data.humidity = ui->humSpinBox->value();
    data.status = ui->statusBox->currentText();

    bool ok = dbManager.updateData(data);
    if(!ok){
        QMessageBox::critical(this, "失败", "修改数据失败!");
        statusBar()->showMessage("数据修改失败!",3000);
        return;
    }

    refreshTable();
    clearInput();

    statusBar()->showMessage("数据已修改!",3000);
}

void MainWindow::onSearchClicked()
{
    if(!tableModel){
        return;
    }

    QStringList filters;

    QString deviceName = ui->searchNameEdit->text().trimmed();
    QString status = ui->searchStatusBox->currentText();

    double minTemp = ui->minTempSpinBox->value();
    double maxTemp = ui->maxTempSpinBox->value();

    QDateTime startTime = ui->startTimeEdit->dateTime();
    QDateTime endTime = ui->endTimeEdit->dateTime();

    if(minTemp > maxTemp){
        QMessageBox::warning(this, "提示", "最低温度不能大于最高温度！");
        return;
    }

    if (startTime > endTime) {
        QMessageBox::warning(this, "提示", "开始时间不能晚于结束时间！");
        return;
    }

    if(!deviceName.isEmpty()){
        deviceName.replace("'","''");
        filters << QString("device_name like '%%1%'").arg(deviceName);
    }

    if(status != "全部"){
        status.replace("'","''");
        filters << QString("status = '%1'").arg(status);
    }

    filters << QString("temperature >= %1").arg(minTemp);
    filters << QString("temperature <= %1").arg(maxTemp);

    QString startTimeStr = startTime.toString("yyyy-MM-dd HH:mm:ss");
    QString endTimeStr = endTime.toString("yyyy-MM-dd HH:mm:ss");

    filters << QString("created_time >= '%1'").arg(startTimeStr);
    filters << QString("created_time <= '%1'").arg(endTimeStr);

    QString filter = filters.join(" AND ");

    tableModel->setFilter(filter);
    tableModel->select();

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    currentId = -1;
    ui->updateBtn->setEnabled(false);
    ui->deleteBtn->setEnabled(false);
    ui->tableView->clearSelection();

    statusBar()->showMessage("查询完成, 共 "+QString::number(tableModel->rowCount())+" 条记录", 3000);

    updateStats();
}

void MainWindow::onShowAllClicked()
{
    if(!tableModel){
        return;
    }

    tableModel->setFilter("");
    tableModel->select();

    ui->searchNameEdit->clear();
    ui->searchStatusBox->setCurrentIndex(0);

    ui->minTempSpinBox->setValue(-50.0);
    ui->maxTempSpinBox->setValue(100.0);

    ui->startTimeEdit->setDateTime(QDateTime::currentDateTime().addDays(-7));
    ui->endTimeEdit->setDateTime(QDateTime::currentDateTime());

    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    currentId = -1;
    ui->updateBtn->setEnabled(false);
    ui->deleteBtn->setEnabled(false);
    ui->tableView->clearSelection();

    statusBar()->showMessage("已显示全部数据, 共 "+QString::number(tableModel->rowCount())+" 条记录", 3000);

    updateStats();
}

void MainWindow::onExportClicked()
{
    if(!tableModel){
        QMessageBox::warning(this, "提示", "表格数据不存在，无法导出!");
        return;
    }

    if(tableModel->rowCount() == 0){
        QMessageBox::warning(this, "提示", "当前表格没有数据，无法导出!");
        return;
    }

    QString defaultFileName = "device_name" + QDateTime::currentDateTime().toString("yyMMdd_HHmmss") + ".csv";
    QString filePath = QFileDialog::getSaveFileName(this,"导出csv文件",defaultFileName,"*.csv");

    if(filePath.isEmpty()){
        statusBar()->showMessage("已取消导出", 3000);
        return;
    }

    if(!filePath.endsWith(".csv", Qt::CaseInsensitive)){
        filePath += ".csv";
    }

    if(!CsvExporter::exportToCsv(filePath,tableModel)){
        QMessageBox::critical(this, "错误", "导出 CSV 失败!");
        statusBar()->showMessage("导出 CSV 失败", 3000);
        return;
    }

    statusBar()->showMessage("导出 CSV 成功:" + filePath, 5000);
    QMessageBox::information(this, "成功", "CSV 导出成功!");
}

void MainWindow::updateStats()
{
    if(!tableModel){
        return;
    }

    while(tableModel->canFetchMore()){
        tableModel->fetchMore();
    }

    int rowCount = tableModel->rowCount();
    ui->totalLabel->setText("总记录: " + QString::number(rowCount));

    if (rowCount == 0) {
        ui->maxTempLabel->setText("最高温度：--");
        ui->minTempLabel->setText("最低温度：--");
        ui->avgTempLabel->setText("平均温度：--");
        ui->alarmCountLabel->setText("报警次数：0");
        return;
    }

    double minTemp = tableModel->data(tableModel->index(0,2)).toDouble();
    double maxTemp = tableModel->data(tableModel->index(0,2)).toDouble();
    double sumTemp = 0.0;
    int alarmCount = 0;

    for(int row=0; row<rowCount; ++row){
        double temperature = tableModel->data(tableModel->index(row,2)).toDouble();
        QString status = tableModel->data(tableModel->index(row,4)).toString();

        if(temperature > maxTemp){
            maxTemp = temperature;
        }
        if(temperature < minTemp){
            minTemp = temperature;
        }
        if(status == "报警"){
            alarmCount++;
        }
        sumTemp += temperature;
    }

    double avgTemp = sumTemp/rowCount;

    ui->maxTempLabel->setText("最高温度:" + QString::number(maxTemp, 'f', 1) + "℃");
    ui->minTempLabel->setText("最低温度:" + QString::number(minTemp, 'f', 1) + "℃");
    ui->avgTempLabel->setText("平均温度:" + QString::number(avgTemp, 'f', 1) + "℃");
    ui->alarmCountLabel->setText("报警次数:" + QString::number(alarmCount));
}

void MainWindow::onGenerateClicked()
{
    generateOneData(true);
}

void MainWindow::onStartTimerClicked()
{
    if (!autoTimer) {
        return;
    }

    int interval = ui->intervalSpinBox->value();

    autoTimer->start(interval);

    ui->startTimerBtn->setEnabled(false);
    ui->stopTimerBtn->setEnabled(true);
    ui->intervalSpinBox->setEnabled(false);

    statusBar()->showMessage("自动采集中，间隔：" + QString::number(interval) + " ms");
}

void MainWindow::onStopTimerClicked()
{
    if (!autoTimer) {
        return;
    }

    autoTimer->stop();

    ui->startTimerBtn->setEnabled(true);
    ui->stopTimerBtn->setEnabled(false);
    ui->intervalSpinBox->setEnabled(true);

    statusBar()->showMessage("自动采集已停止", 3000);
}

void MainWindow::generateOneData(bool showMessage)
{
    deviceData data = DataGenerator::generate();

    if (!dbManager.insertData(data)) {
        if (showMessage) {
            QMessageBox::critical(this, "错误", "生成模拟数据失败！");
        }

        statusBar()->showMessage("生成模拟数据失败", 3000);
        return;
    }

    refreshTable();
    clearInput();

    QString status = data.temperature >= 38.0 ? "报警" : data.status;

    QString message;

    if (data.temperature >= 38.0) {
        message = "生成模拟数据成功，触发温度报警：" + data.deviceName + "，温度：" + QString::number(data.temperature, 'f', 1) + " ℃";
    } else {
        message = "生成模拟数据成功：" + data.deviceName + "，温度：" + QString::number(data.temperature, 'f', 1) + " ℃，状态：" + status;
    }

    statusBar()->showMessage(message, 3000);

    if (showMessage) {
        // 不弹窗也可以，这里保持状态栏提示即可
    }
}

bool MainWindow::checkInput()
{
    QString deviceName = ui->deviceNameEdit->text().trimmed();
    if(deviceName.isEmpty()){
        QMessageBox::warning(this, "错误", "设备名不能为空!");
        ui->deviceNameEdit->setFocus();
        return false;
    }

    double temp = ui->tempSpinBox->value();
    if(temp>100 || temp<-50){
        QMessageBox::warning(this, "提示", "温度范围不合理!");
        ui->tempSpinBox->setFocus();
        return false;
    }

    int hum = ui->humSpinBox->value();
    if(hum<0 || hum>100){
        QMessageBox::warning(this, "提示", "湿度范围必须在 0 到 100 之间!");
        ui->humSpinBox->setFocus();
        return false;
    }

    return true;
}
