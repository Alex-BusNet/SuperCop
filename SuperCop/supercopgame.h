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
    int lastKeyPress;

public:
    void paintEvent(QPaintEvent *e);
    explicit SuperCopGame(QWidget *parent = 0);
    ~SuperCopGame();

    void keyPressEvent(QKeyEvent *evt);
    void setLastKeyPress(int keyPress);

signals:

public slots:
    void updateField();
};

#endif // SUPERCOPGAME_H
