#include "donut.h"
#include "supercopgame.h"
#include <QDebug>
#include <QTimer>

Donut::Donut(QWidget *parent)
{
    posX = 670;
    posY = parent->height() - 270;
    sizeX = 30;
    sizeY = 30;
    donut = new QPixmap("../SuperCop/Images/donut.png");
    moveTimer = new QTimer();
    moveTimer->setInterval(10);
    moveTimer->start();
    speed=0;//Donut has a speed. 4 is an arbitrary standard speed for "non-moving" objects for now.
}

Donut::~Donut()
{
    delete donut;
    moveTimer->stop();
    delete moveTimer;
}//clears potential memory leaks

void Donut::drawDonut(QPainter &painter)
{
    painter.drawPixmap(posX, posY, sizeX, sizeY, *donut);
    posX-=speed;
}

void Donut::changeImage(QString str)
{
    delete donut;
    donut = new QPixmap(str);
}

void Donut::eaten()
{
    posX=650;
    speed=0;
}

void Donut::noteaten()
{
    posX=650;
    speed=0;
}




void Donut::setPosX(int x)
{
    posX=x;
}//Mutator

void Donut::setPosY(int y)
{
    posY=y;
}//Mutator

void Donut::setSizeX(int x)
{
    sizeX=x;
}//Mutator

void Donut::setSizeY(int y)
{
    sizeY=y;
}//Mutator

void Donut::setSpeed(int speed)
{
    this->speed=speed;
}//Mutator

int Donut::getPosX()
{
    return posX;
}//Accessor

int Donut::getPosY()
{
    return posY;
}//Accessor

int Donut::getSizeX()
{
    return sizeX;
}//Accessor

int Donut::getSizeY()
{
    return sizeY;
}//Accessor

int Donut::getSpeed()
{
   return speed;
}//Accessor

