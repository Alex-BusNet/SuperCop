#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contactus.h"
#include "controls.h"
#include "highscores.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionContact_Us_triggered();

    void on_actionControls_triggered();

    void on_actionHigh_Scores_triggered();

private:
    Ui::MainWindow *ui;
    ContactUs* contact;
    Controls* controls;
    HighScores* hScore;
};

#endif // MAINWINDOW_H
