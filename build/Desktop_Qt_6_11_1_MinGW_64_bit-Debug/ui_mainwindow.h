/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *deviceNamewidget;
    QHBoxLayout *horizontalLayout;
    QLabel *deviceNameLabel;
    QLineEdit *deviceNameEdit;
    QWidget *tempWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *tempLabel;
    QDoubleSpinBox *tempSpinBox;
    QSpacerItem *horizontalSpacer;
    QWidget *humWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *humLabel;
    QSpinBox *humSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QWidget *statusWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *statusLabel;
    QComboBox *statusBox;
    QSpacerItem *horizontalSpacer_3;
    QWidget *btnWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn;
    QPushButton *clearBtn;
    QGroupBox *searchBox;
    QVBoxLayout *verticalLayout_2;
    QWidget *searchNameWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *searchNameLabel;
    QLineEdit *searchNameEdit;
    QWidget *searchStatusWidget;
    QHBoxLayout *horizontalLayout_7;
    QLabel *searchStatusLabel;
    QComboBox *searchStatusBox;
    QSpacerItem *horizontalSpacer_4;
    QWidget *searchTempWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *searchTempLabel;
    QDoubleSpinBox *minTempSpinBox;
    QLabel *label_1;
    QDoubleSpinBox *maxTempSpinBox;
    QSpacerItem *horizontalSpacer_6;
    QWidget *searchTimeWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *searchTimeLabel;
    QDateTimeEdit *startTimeEdit;
    QLabel *label_2;
    QDateTimeEdit *endTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QWidget *searchBtnWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *searchBtn;
    QPushButton *showAllBtn;
    QPushButton *exportBtn;
    QGroupBox *SimulationBox;
    QVBoxLayout *verticalLayout_3;
    QWidget *BtnWidget;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *generateBtn;
    QPushButton *startTimerBtn;
    QPushButton *stopTimerBtn;
    QWidget *intervalWidget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *intervalLabel;
    QSpinBox *intervalSpinBox;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *StatisticsBox;
    QVBoxLayout *verticalLayout_4;
    QLabel *totalLabel;
    QLabel *maxTempLabel;
    QLabel *minTempLabel;
    QLabel *avgTempLabel;
    QLabel *alarmCountLabel;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_13;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1786, 1148);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        deviceNamewidget = new QWidget(groupBox);
        deviceNamewidget->setObjectName("deviceNamewidget");
        horizontalLayout = new QHBoxLayout(deviceNamewidget);
        horizontalLayout->setObjectName("horizontalLayout");
        deviceNameLabel = new QLabel(deviceNamewidget);
        deviceNameLabel->setObjectName("deviceNameLabel");

        horizontalLayout->addWidget(deviceNameLabel);

        deviceNameEdit = new QLineEdit(deviceNamewidget);
        deviceNameEdit->setObjectName("deviceNameEdit");

        horizontalLayout->addWidget(deviceNameEdit);


        verticalLayout->addWidget(deviceNamewidget);

        tempWidget = new QWidget(groupBox);
        tempWidget->setObjectName("tempWidget");
        horizontalLayout_2 = new QHBoxLayout(tempWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        tempLabel = new QLabel(tempWidget);
        tempLabel->setObjectName("tempLabel");

        horizontalLayout_2->addWidget(tempLabel);

        tempSpinBox = new QDoubleSpinBox(tempWidget);
        tempSpinBox->setObjectName("tempSpinBox");

        horizontalLayout_2->addWidget(tempSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(tempWidget);

        humWidget = new QWidget(groupBox);
        humWidget->setObjectName("humWidget");
        horizontalLayout_3 = new QHBoxLayout(humWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        humLabel = new QLabel(humWidget);
        humLabel->setObjectName("humLabel");

        horizontalLayout_3->addWidget(humLabel);

        humSpinBox = new QSpinBox(humWidget);
        humSpinBox->setObjectName("humSpinBox");

        horizontalLayout_3->addWidget(humSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(humWidget);

        statusWidget = new QWidget(groupBox);
        statusWidget->setObjectName("statusWidget");
        horizontalLayout_4 = new QHBoxLayout(statusWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        statusLabel = new QLabel(statusWidget);
        statusLabel->setObjectName("statusLabel");

        horizontalLayout_4->addWidget(statusLabel);

        statusBox = new QComboBox(statusWidget);
        statusBox->setObjectName("statusBox");

        horizontalLayout_4->addWidget(statusBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(statusWidget);

        btnWidget = new QWidget(groupBox);
        btnWidget->setObjectName("btnWidget");
        horizontalLayout_5 = new QHBoxLayout(btnWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        addBtn = new QPushButton(btnWidget);
        addBtn->setObjectName("addBtn");

        horizontalLayout_5->addWidget(addBtn);

        updateBtn = new QPushButton(btnWidget);
        updateBtn->setObjectName("updateBtn");

        horizontalLayout_5->addWidget(updateBtn);

        deleteBtn = new QPushButton(btnWidget);
        deleteBtn->setObjectName("deleteBtn");

        horizontalLayout_5->addWidget(deleteBtn);

        clearBtn = new QPushButton(btnWidget);
        clearBtn->setObjectName("clearBtn");

        horizontalLayout_5->addWidget(clearBtn);


        verticalLayout->addWidget(btnWidget);


        verticalLayout_5->addWidget(groupBox);

        searchBox = new QGroupBox(centralwidget);
        searchBox->setObjectName("searchBox");
        verticalLayout_2 = new QVBoxLayout(searchBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        searchNameWidget = new QWidget(searchBox);
        searchNameWidget->setObjectName("searchNameWidget");
        horizontalLayout_6 = new QHBoxLayout(searchNameWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        searchNameLabel = new QLabel(searchNameWidget);
        searchNameLabel->setObjectName("searchNameLabel");

        horizontalLayout_6->addWidget(searchNameLabel);

        searchNameEdit = new QLineEdit(searchNameWidget);
        searchNameEdit->setObjectName("searchNameEdit");

        horizontalLayout_6->addWidget(searchNameEdit);


        verticalLayout_2->addWidget(searchNameWidget);

        searchStatusWidget = new QWidget(searchBox);
        searchStatusWidget->setObjectName("searchStatusWidget");
        horizontalLayout_7 = new QHBoxLayout(searchStatusWidget);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        searchStatusLabel = new QLabel(searchStatusWidget);
        searchStatusLabel->setObjectName("searchStatusLabel");

        horizontalLayout_7->addWidget(searchStatusLabel);

        searchStatusBox = new QComboBox(searchStatusWidget);
        searchStatusBox->setObjectName("searchStatusBox");

        horizontalLayout_7->addWidget(searchStatusBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(searchStatusWidget);

        searchTempWidget = new QWidget(searchBox);
        searchTempWidget->setObjectName("searchTempWidget");
        horizontalLayout_8 = new QHBoxLayout(searchTempWidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        searchTempLabel = new QLabel(searchTempWidget);
        searchTempLabel->setObjectName("searchTempLabel");

        horizontalLayout_8->addWidget(searchTempLabel);

        minTempSpinBox = new QDoubleSpinBox(searchTempWidget);
        minTempSpinBox->setObjectName("minTempSpinBox");

        horizontalLayout_8->addWidget(minTempSpinBox);

        label_1 = new QLabel(searchTempWidget);
        label_1->setObjectName("label_1");

        horizontalLayout_8->addWidget(label_1);

        maxTempSpinBox = new QDoubleSpinBox(searchTempWidget);
        maxTempSpinBox->setObjectName("maxTempSpinBox");

        horizontalLayout_8->addWidget(maxTempSpinBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(searchTempWidget);

        searchTimeWidget = new QWidget(searchBox);
        searchTimeWidget->setObjectName("searchTimeWidget");
        horizontalLayout_9 = new QHBoxLayout(searchTimeWidget);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        searchTimeLabel = new QLabel(searchTimeWidget);
        searchTimeLabel->setObjectName("searchTimeLabel");

        horizontalLayout_9->addWidget(searchTimeLabel);

        startTimeEdit = new QDateTimeEdit(searchTimeWidget);
        startTimeEdit->setObjectName("startTimeEdit");

        horizontalLayout_9->addWidget(startTimeEdit);

        label_2 = new QLabel(searchTimeWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_9->addWidget(label_2);

        endTimeEdit = new QDateTimeEdit(searchTimeWidget);
        endTimeEdit->setObjectName("endTimeEdit");

        horizontalLayout_9->addWidget(endTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(searchTimeWidget);

        searchBtnWidget = new QWidget(searchBox);
        searchBtnWidget->setObjectName("searchBtnWidget");
        horizontalLayout_10 = new QHBoxLayout(searchBtnWidget);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        searchBtn = new QPushButton(searchBtnWidget);
        searchBtn->setObjectName("searchBtn");

        horizontalLayout_10->addWidget(searchBtn);

        showAllBtn = new QPushButton(searchBtnWidget);
        showAllBtn->setObjectName("showAllBtn");

        horizontalLayout_10->addWidget(showAllBtn);

        exportBtn = new QPushButton(searchBtnWidget);
        exportBtn->setObjectName("exportBtn");

        horizontalLayout_10->addWidget(exportBtn);


        verticalLayout_2->addWidget(searchBtnWidget);


        verticalLayout_5->addWidget(searchBox);

        SimulationBox = new QGroupBox(centralwidget);
        SimulationBox->setObjectName("SimulationBox");
        verticalLayout_3 = new QVBoxLayout(SimulationBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        BtnWidget = new QWidget(SimulationBox);
        BtnWidget->setObjectName("BtnWidget");
        horizontalLayout_11 = new QHBoxLayout(BtnWidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        generateBtn = new QPushButton(BtnWidget);
        generateBtn->setObjectName("generateBtn");

        horizontalLayout_11->addWidget(generateBtn);

        startTimerBtn = new QPushButton(BtnWidget);
        startTimerBtn->setObjectName("startTimerBtn");

        horizontalLayout_11->addWidget(startTimerBtn);

        stopTimerBtn = new QPushButton(BtnWidget);
        stopTimerBtn->setObjectName("stopTimerBtn");

        horizontalLayout_11->addWidget(stopTimerBtn);


        verticalLayout_3->addWidget(BtnWidget);

        intervalWidget = new QWidget(SimulationBox);
        intervalWidget->setObjectName("intervalWidget");
        horizontalLayout_12 = new QHBoxLayout(intervalWidget);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        intervalLabel = new QLabel(intervalWidget);
        intervalLabel->setObjectName("intervalLabel");

        horizontalLayout_12->addWidget(intervalLabel);

        intervalSpinBox = new QSpinBox(intervalWidget);
        intervalSpinBox->setObjectName("intervalSpinBox");

        horizontalLayout_12->addWidget(intervalSpinBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(intervalWidget);


        verticalLayout_5->addWidget(SimulationBox);

        StatisticsBox = new QGroupBox(centralwidget);
        StatisticsBox->setObjectName("StatisticsBox");
        verticalLayout_4 = new QVBoxLayout(StatisticsBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        totalLabel = new QLabel(StatisticsBox);
        totalLabel->setObjectName("totalLabel");

        verticalLayout_4->addWidget(totalLabel);

        maxTempLabel = new QLabel(StatisticsBox);
        maxTempLabel->setObjectName("maxTempLabel");

        verticalLayout_4->addWidget(maxTempLabel);

        minTempLabel = new QLabel(StatisticsBox);
        minTempLabel->setObjectName("minTempLabel");

        verticalLayout_4->addWidget(minTempLabel);

        avgTempLabel = new QLabel(StatisticsBox);
        avgTempLabel->setObjectName("avgTempLabel");

        verticalLayout_4->addWidget(avgTempLabel);

        alarmCountLabel = new QLabel(StatisticsBox);
        alarmCountLabel->setObjectName("alarmCountLabel");

        verticalLayout_4->addWidget(alarmCountLabel);


        verticalLayout_5->addWidget(StatisticsBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_13 = new QHBoxLayout(groupBox_2);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");

        horizontalLayout_13->addWidget(tableView);


        verticalLayout_5->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1786, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\275\225\345\205\245", nullptr));
        deviceNameLabel->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\220\215\357\274\232", nullptr));
        tempLabel->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        humLabel->setText(QCoreApplication::translate("MainWindow", "\346\271\277\345\272\246\357\274\232", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        updateBtn->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\346\215\256", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        searchBox->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\235\241\344\273\266", nullptr));
        searchNameLabel->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\345\220\215\357\274\232", nullptr));
        searchStatusLabel->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        searchTempLabel->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\357\274\232", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        searchTimeLabel->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        showAllBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
        exportBtn->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272CSV", nullptr));
        SimulationBox->setTitle(QCoreApplication::translate("MainWindow", "\345\256\236\346\227\266\346\250\241\346\213\237", nullptr));
        generateBtn->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\344\270\200\346\235\241\346\250\241\346\213\237\346\225\260\346\215\256", nullptr));
        startTimerBtn->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\207\252\345\212\250\351\207\207\351\233\206", nullptr));
        stopTimerBtn->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\350\207\252\345\212\250\351\207\207\351\233\206", nullptr));
        intervalLabel->setText(QCoreApplication::translate("MainWindow", "\351\207\207\351\233\206\351\227\264\351\232\224\357\274\232", nullptr));
        StatisticsBox->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        totalLabel->setText(QCoreApplication::translate("MainWindow", "\346\200\273\350\256\260\345\275\225\357\274\2320", nullptr));
        maxTempLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\200\351\253\230\346\270\251\345\272\246\357\274\232--", nullptr));
        minTempLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\275\216\346\270\251\345\272\246\357\274\232--", nullptr));
        avgTempLabel->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\235\207\346\270\251\345\272\246\357\274\232--", nullptr));
        alarmCountLabel->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\346\254\241\346\225\260\357\274\2320", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
