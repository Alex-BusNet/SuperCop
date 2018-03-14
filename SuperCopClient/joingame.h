#ifndef JOINGAME_H
#define JOINGAME_H

#include <QWidget>
#include <QTcpSocket>
#include "renderobject.h"
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <QGenericMatrix>
#include <vector>
using namespace std;

namespace Ui {
class JoinGame;
}

class JoinGame : public QWidget
{
    Q_OBJECT

public:
    explicit JoinGame(QWidget *parent = 0);
    ~JoinGame();
    QString nickname;
    QString hostIP;
    void setHostIP(QString address);
    void closeEvent(QCloseEvent *e);

    int direction1;
    int direction2;
    QMessageBox *msg;
    QMessageBox *pbox;

private slots:
    void on_pushButton_clicked();
    void Disconnected();
    void readyRead();

    void on_Jump_clicked();
    void on_Left_clicked();
    void on_Right_clicked();
    void on_EndJump_clicked();

private:
    Ui::JoinGame *ui;
    QTcpSocket *socket;
    void updateField();
};

#endif // JOINGAME_H
