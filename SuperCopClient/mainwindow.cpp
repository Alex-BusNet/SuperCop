//Sam Stein and Joey Rockwood
//This file contains the coding to make the Main window run and update properly,
//and to make the menus accessible to the user.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QDir>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
     //Declare Variables and set background image for main window
    ui->setupUi(this);
    QPixmap bkgnd("images/Snake.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    join=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
   delete join;
}

void MainWindow::on_actionQuit_triggered()
{
    //Close main window
    this->close();
}

void MainWindow::on_action2_Player_Join_triggered()
{//Displays Join Dialogue for Network Multiplayer
    if(join==NULL){
        join = new JoinGame();
    }
    join->show();
}
