//Alex Portolese and Sam Stein
//This file contains the declarations for the Wall object.
#ifndef WALL_H
#define WALL_H

#include "donut.h"
#include "enemy.h"
#include <QPixmap>
#include <QPainter>
#include <QWidget>


class Wall
{
private:
    QPixmap *wall;
//    QPixmap *fire;
    QRect *rectWall;
//    QWidget *par;
    int picX, picY;
//    int firePicX, firePicY;
    int gameWindow, wallState;
    int wallPosX, wallPosY;
//    int firePosX, firePosY;

    bool wallHasEnemy, active;
//bool wallHasFire;
//    enum wallType {PLAIN = 0, FIRE = 1, ENEMY = 2};

public:
    Wall(QWidget *parent);
    ~Wall(); 

    void drawWall(QPainter &painter);
//    void drawFire(QPainter &painter);

    void setWallPosX(int x);
    void setWallPosY(int y);
//    void setFirePosX(int x);
//    void setFirePosY(int y);
//    void setWallOnFire(bool fire);
//    void setEnemyOnWall(bool enemy);
//    void setWallState(enum Wall::wallType state);

    int getWallPosX();
    int getWallPosY();
    int getWallSizeX();
    int getWallSizeY();
//    int getFirePosX();
//    int getFirePosY();
//    int getWallType();
    void setActive(bool act);
    bool getActive();
};

#endif // WALL_H
