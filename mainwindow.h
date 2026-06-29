#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "databasemanager.h"

#include <QMainWindow>
#include <QSqlTableModel>
#include <QModelIndex>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    void initUi();
    void initTable();
    void initTimer();
    void refreshTable();
    void applyStyle();

    void onAddClicked();
    void onTableClicked(const QModelIndex& index);
    void onDeleteClicked();
    void clearInput();
    void onUpdateClicked();
    void onSearchClicked();
    void onShowAllClicked();
    void onExportClicked();
    void updateStats();
    void onGenerateClicked();
    void onStartTimerClicked();
    void onStopTimerClicked();
    void generateOneData(bool showMessage = true);

    bool checkInput();
private:
    Ui::MainWindow *ui;
    DatabaseManager dbManager;
    QSqlTableModel *tableModel;
    int currentId;
    QTimer* autoTimer = nullptr;

};
#endif // MAINWINDOW_H
