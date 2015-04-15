#ifndef SUPERCOPGAME_H
#define SUPERCOPGAME_H


#include "player.h"
#include <QWidget>
#include <QGraphicsItem>
#include <QtCore>
#include <QtGui>
#include <QQmlEngine>
#include <QQuickView>
#include <QTimer>
#include <QKeyEvent>


#include <QMessageBox>
#include "enemy.h"

namespace Ui {
class SuperCopGame;
}

class SuperCopGame : public QWidget
{
    Q_OBJECT


private:
    enum keyPressed {NONE = 0, RIGHT = 1, UP = 2, DOWN = 3, LEFT = 4};
    Ui::SuperCopGame *ui;

    Player *player;
    QTimer *timer;
    QTimer *keyTimer;
    int lastKeyPress;
    bool isUpPressed, isDownPressed, isLeftPressed, isRightPressed;


    bool paused;
    QPixmap* robot;
    int picX,picY;
    int picHeight, picWidth;
    int gamescore;
    Enemy *enemy;
    int gameover;

public:
    void paintEvent(QPaintEvent *e);
    explicit SuperCopGame(QWidget *parent = 0);
    ~SuperCopGame();

    void keyPressEvent(QKeyEvent *evt);
    void keyReleaseEvent(QKeyEvent *evt);
    void setLastKeyPress(int keyPress);
signals:

public slots:
    void pollKey();
    void updateField();

};

#endif // SUPERCOPGAME_H
