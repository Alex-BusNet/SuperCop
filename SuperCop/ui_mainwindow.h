/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *Easy_1P;
    QAction *Medium_1P;
    QAction *Hard_1P;
    QAction *actionContact_Us;
    QAction *actionControls;
    QAction *actionHigh_Scores;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *easy;
    QPushButton *medium;
    QPushButton *hard;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *highscores;
    QPushButton *exit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew_1_Player_Game;
    QMenu *menuCredits;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        MainWindow->setMinimumSize(QSize(400, 300));
        MainWindow->setMaximumSize(QSize(400, 300));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        Easy_1P = new QAction(MainWindow);
        Easy_1P->setObjectName(QStringLiteral("Easy_1P"));
        Easy_1P->setEnabled(true);
        Medium_1P = new QAction(MainWindow);
        Medium_1P->setObjectName(QStringLiteral("Medium_1P"));
        Hard_1P = new QAction(MainWindow);
        Hard_1P->setObjectName(QStringLiteral("Hard_1P"));
        actionContact_Us = new QAction(MainWindow);
        actionContact_Us->setObjectName(QStringLiteral("actionContact_Us"));
        actionControls = new QAction(MainWindow);
        actionControls->setObjectName(QStringLiteral("actionControls"));
        actionHigh_Scores = new QAction(MainWindow);
        actionHigh_Scores->setObjectName(QStringLiteral("actionHigh_Scores"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 130, 351, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        easy = new QPushButton(verticalLayoutWidget);
        easy->setObjectName(QStringLiteral("easy"));

        horizontalLayout->addWidget(easy);

        medium = new QPushButton(verticalLayoutWidget);
        medium->setObjectName(QStringLiteral("medium"));

        horizontalLayout->addWidget(medium);

        hard = new QPushButton(verticalLayoutWidget);
        hard->setObjectName(QStringLiteral("hard"));

        horizontalLayout->addWidget(hard);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        highscores = new QPushButton(verticalLayoutWidget);
        highscores->setObjectName(QStringLiteral("highscores"));

        horizontalLayout_2->addWidget(highscores);

        exit = new QPushButton(verticalLayoutWidget);
        exit->setObjectName(QStringLiteral("exit"));

        horizontalLayout_2->addWidget(exit);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew_1_Player_Game = new QMenu(menuFile);
        menuNew_1_Player_Game->setObjectName(QStringLiteral("menuNew_1_Player_Game"));
        menuCredits = new QMenu(menuBar);
        menuCredits->setObjectName(QStringLiteral("menuCredits"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCredits->menuAction());
        menuFile->addAction(menuNew_1_Player_Game->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionHigh_Scores);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew_1_Player_Game->addAction(Easy_1P);
        menuNew_1_Player_Game->addAction(Medium_1P);
        menuNew_1_Player_Game->addAction(Hard_1P);
        menuCredits->addAction(actionControls);
        menuCredits->addAction(actionContact_Us);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SuperCop", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        Easy_1P->setText(QApplication::translate("MainWindow", "Easy", nullptr));
#ifndef QT_NO_SHORTCUT
        Easy_1P->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_NO_SHORTCUT
        Medium_1P->setText(QApplication::translate("MainWindow", "Medium", nullptr));
#ifndef QT_NO_SHORTCUT
        Medium_1P->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_NO_SHORTCUT
        Hard_1P->setText(QApplication::translate("MainWindow", "Hard", nullptr));
#ifndef QT_NO_SHORTCUT
        Hard_1P->setShortcut(QApplication::translate("MainWindow", "Ctrl+3", nullptr));
#endif // QT_NO_SHORTCUT
        actionContact_Us->setText(QApplication::translate("MainWindow", "Contact Us", nullptr));
#ifndef QT_NO_SHORTCUT
        actionContact_Us->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_NO_SHORTCUT
        actionControls->setText(QApplication::translate("MainWindow", "Controls", nullptr));
#ifndef QT_NO_SHORTCUT
        actionControls->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionHigh_Scores->setText(QApplication::translate("MainWindow", "High Scores", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHigh_Scores->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        easy->setText(QApplication::translate("MainWindow", "Easy", nullptr));
        medium->setText(QApplication::translate("MainWindow", "Medium", nullptr));
        hard->setText(QApplication::translate("MainWindow", "Hard", nullptr));
        highscores->setText(QApplication::translate("MainWindow", "Highscores", nullptr));
        exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuNew_1_Player_Game->setTitle(QApplication::translate("MainWindow", "New Game", nullptr));
        menuCredits->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
