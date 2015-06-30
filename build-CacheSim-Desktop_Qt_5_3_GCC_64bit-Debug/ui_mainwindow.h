/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *memSize;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *cacheSize;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *blockSize;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *mappingType;
    QPushButton *Generate;
    QHBoxLayout *horizontalLayout_7;
    QListWidget *addressList;
    QTableWidget *mainMem;
    QTableWidget *cache;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *addressInput;
    QPushButton *InsertAddress;
    QVBoxLayout *verticalLayout_2;
    QPushButton *runOne;
    QPushButton *runAll;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLCDNumber *HIT;
    QLabel *MissRate;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLCDNumber *MISS;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(896, 616);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_10 = new QHBoxLayout(centralWidget);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        memSize = new QLineEdit(centralWidget);
        memSize->setObjectName(QStringLiteral("memSize"));

        horizontalLayout->addWidget(memSize);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        cacheSize = new QLineEdit(centralWidget);
        cacheSize->setObjectName(QStringLiteral("cacheSize"));

        horizontalLayout_4->addWidget(cacheSize);


        horizontalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        blockSize = new QSpinBox(centralWidget);
        blockSize->setObjectName(QStringLiteral("blockSize"));
        blockSize->setValue(1);

        horizontalLayout_3->addWidget(blockSize);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        mappingType = new QComboBox(centralWidget);
        mappingType->setObjectName(QStringLiteral("mappingType"));

        horizontalLayout_2->addWidget(mappingType);


        horizontalLayout_9->addLayout(horizontalLayout_2);

        Generate = new QPushButton(centralWidget);
        Generate->setObjectName(QStringLiteral("Generate"));

        horizontalLayout_9->addWidget(Generate);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(9, -1, -1, -1);
        addressList = new QListWidget(centralWidget);
        addressList->setObjectName(QStringLiteral("addressList"));

        horizontalLayout_7->addWidget(addressList);

        mainMem = new QTableWidget(centralWidget);
        mainMem->setObjectName(QStringLiteral("mainMem"));

        horizontalLayout_7->addWidget(mainMem);

        cache = new QTableWidget(centralWidget);
        cache->setObjectName(QStringLiteral("cache"));

        horizontalLayout_7->addWidget(cache);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 2);
        horizontalLayout_7->setStretch(2, 8);

        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        addressInput = new QLineEdit(centralWidget);
        addressInput->setObjectName(QStringLiteral("addressInput"));

        verticalLayout_3->addWidget(addressInput);

        InsertAddress = new QPushButton(centralWidget);
        InsertAddress->setObjectName(QStringLiteral("InsertAddress"));

        verticalLayout_3->addWidget(InsertAddress);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        runOne = new QPushButton(centralWidget);
        runOne->setObjectName(QStringLiteral("runOne"));

        verticalLayout_2->addWidget(runOne);

        runAll = new QPushButton(centralWidget);
        runAll->setObjectName(QStringLiteral("runAll"));

        verticalLayout_2->addWidget(runAll);


        horizontalLayout_8->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        HIT = new QLCDNumber(centralWidget);
        HIT->setObjectName(QStringLiteral("HIT"));

        horizontalLayout_5->addWidget(HIT);

        MissRate = new QLabel(centralWidget);
        MissRate->setObjectName(QStringLiteral("MissRate"));

        horizontalLayout_5->addWidget(MissRate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        MISS = new QLCDNumber(centralWidget);
        MISS->setObjectName(QStringLiteral("MISS"));

        horizontalLayout_6->addWidget(MISS);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        horizontalLayout_8->setStretch(0, 2);
        horizontalLayout_8->setStretch(1, 2);
        horizontalLayout_8->setStretch(2, 8);

        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Memory Size", 0));
        label_4->setText(QApplication::translate("MainWindow", "Cache Size", 0));
        label_3->setText(QApplication::translate("MainWindow", "Block Size", 0));
        label_2->setText(QApplication::translate("MainWindow", "Mapping Type", 0));
        mappingType->clear();
        mappingType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "8", 0)
        );
        Generate->setText(QApplication::translate("MainWindow", "Generate", 0));
        InsertAddress->setText(QApplication::translate("MainWindow", "Insert", 0));
        runOne->setText(QApplication::translate("MainWindow", "RunOne", 0));
        runAll->setText(QApplication::translate("MainWindow", "RunAll", 0));
        label_5->setText(QApplication::translate("MainWindow", "HIT ", 0));
        MissRate->setText(QApplication::translate("MainWindow", "MissRate : ", 0));
        label_6->setText(QApplication::translate("MainWindow", "MISS", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
