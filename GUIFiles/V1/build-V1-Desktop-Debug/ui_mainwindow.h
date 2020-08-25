/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *GamesTab;
    QWidget *TeamsTab;
    QWidget *PlayersTab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *TablePlayers;
    QPushButton *SearchPlayersButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ReturnButton;
    QWidget *SettingsTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 751, 531));
        GamesTab = new QWidget();
        GamesTab->setObjectName(QStringLiteral("GamesTab"));
        tabWidget->addTab(GamesTab, QString());
        TeamsTab = new QWidget();
        TeamsTab->setObjectName(QStringLiteral("TeamsTab"));
        tabWidget->addTab(TeamsTab, QString());
        PlayersTab = new QWidget();
        PlayersTab->setObjectName(QStringLiteral("PlayersTab"));
        verticalLayoutWidget = new QWidget(PlayersTab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 30, 721, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        TablePlayers = new QTableWidget(verticalLayoutWidget);
        if (TablePlayers->columnCount() < 2)
            TablePlayers->setColumnCount(2);
        TablePlayers->setObjectName(QStringLiteral("TablePlayers"));
        TablePlayers->setColumnCount(2);
        TablePlayers->horizontalHeader()->setCascadingSectionResizes(false);
        TablePlayers->horizontalHeader()->setStretchLastSection(true);
        TablePlayers->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(TablePlayers);

        SearchPlayersButton = new QPushButton(verticalLayoutWidget);
        SearchPlayersButton->setObjectName(QStringLiteral("SearchPlayersButton"));

        verticalLayout->addWidget(SearchPlayersButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ReturnButton = new QPushButton(verticalLayoutWidget);
        ReturnButton->setObjectName(QStringLiteral("ReturnButton"));

        horizontalLayout->addWidget(ReturnButton);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget->addTab(PlayersTab, QString());
        SettingsTab = new QWidget();
        SettingsTab->setObjectName(QStringLiteral("SettingsTab"));
        tabWidget->addTab(SettingsTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(GamesTab), QApplication::translate("MainWindow", "Games", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(TeamsTab), QApplication::translate("MainWindow", "Teams", Q_NULLPTR));
        SearchPlayersButton->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        ReturnButton->setText(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(PlayersTab), QApplication::translate("MainWindow", "Players", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(SettingsTab), QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
