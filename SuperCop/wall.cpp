#include "wall.h"

Wall::Wall(QWidget *parent)
{
    posX = 700;
    posY = parent->height() - 220;
    sizeX = 85;
    sizeY = 85;
    wall = new QPixmap("../SuperCop/Images/wall.png");
    moveTimer = new QTimer();
    moveTimer->setInterval(40);
    moveTimer->start();
    speed=0;//Wall has a speed. 4 is an arbitrary standard speed for "non-moving" objects for now.
}

Wall::~Wall()
{
    delete wall;
    moveTimer->stop();
    delete moveTimer;
}//clears potential memory leaks

void Wall::drawWall(QPainter &painter)
{
    painter.drawPixmap(posX, posY, sizeX, sizeY, *wall);
    posX-=speed;
}

void Wall::changeImage(QString str)
{
    delete wall;
    wall = new QPixmap(str);
}


void Wall::setPosX(int x)
{
    posX=x;
}//Mutator

void Wall::setPosY(int y)
{
    posY=y;
}//Mutator

void Wall::setSizeX(int x)
{
    sizeX=x;
}//Mutator

void Wall::setSizeY(int y)
{
    sizeY=y;
}//Mutator

void Wall::setSpeed(int speed)
{
    this->speed=speed;
}//Mutator

int Wall::getPosX()
{
    return posX;
}//Accessor

int Wall::getPosY()
{
    return posY;
}//Accessor

int Wall::getSizeX()
{
    return sizeX;
}//Accessor

int Wall::getSizeY()
{
    return sizeY;
}//Accessor

int Wall::getSpeed()
{
   return speed;
}//Accessor

