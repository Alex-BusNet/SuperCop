//Alex Portolese and Sam Stein
//This file contains the coding to make the Wall functional.
#include "wall.h"

Wall::Wall(QWidget *parent)
{
    wall = new QPixmap("../SuperCop/Images/Wall/0.png");
//    fire = new QPixmap("../SuperCop/Images/Fire/fire.png");

    gameWindow = parent->width();
    wallPosY = parent->height() - 140;
    wallPosX = gameWindow +50;
    picX = 32;
    picY = 50;
    active=false;

//    firePicX = 30;
//    firePicY = 21;
//    firePosX = wallPosX + 1;
//    firePosY = wallPosY - 21;
//    wallState = 0;

}//initializes the wall variables


Wall::~Wall()
{
    delete wall;
}

void Wall::drawWall(QPainter &painter)
{
    rectWall = new QRect(wallPosX, wallPosY, picX, picY);
    painter.drawRect(*rectWall);
    QBrush brush;
    brush.setTexture(*wall);
    painter.fillRect(*rectWall, brush);

//    if(wallState == FIRE)
//    {
//        drawFire(painter);
//    }
}//Draws Wall Object

//void Wall::drawFire(QPainter &painter)
//{
//    painter.drawPixmap(firePosX, firePosY, firePicX, firePicY, *fire);
//}//Draws fire object

void Wall::setWallPosX(int x)
{
    this->wallPosX = x;
}//Mutator

void Wall::setWallPosY(int y)
{
    this->wallPosY = y;
}//Mutator

//void Wall::setFirePosX(int x)
//{
//    this->firePosX = x;
//}//Mutator

//void Wall::setWallOnFire(bool fire)
//{
//    this->wallHasFire = fire;
//}//Mutator

//void Wall::setEnemyOnWall(bool enemy)
//{
//    this->wallHasEnemy = enemy;
//}//Mutator

//void Wall::setWallState(enum Wall::wallType state)
//{
//    this->wallState = state;
//}//Mutator

int Wall::getWallPosX()
{
    return this->wallPosX;
}//Accessor

int Wall::getWallPosY()
{
    return this->wallPosY;
}//Accessor

int Wall::getWallSizeX()
{
    return this->picX;
}//Accessor

int Wall::getWallSizeY()
{
    return this->picY;
}//Accessor

//int Wall::getFirePosX()
//{
//    return firePosX;
//}//Accessor

//int Wall::getFirePosY()
//{
//    return firePosY;
//}//Accessor

//int Wall::getWallType()
//{
//    switch(wallState)
//    {
//    case PLAIN:
//        return 0;
//        break;
//    case FIRE:
//        return 1;
//        break;
//    case ENEMY:
//        return 2;
//        break;
//    }
//}//Accessor

bool Wall::getActive()
{
    return active;
}//Mutator

void Wall::setActive(bool act)
{
    active=act;
}//Accessor
