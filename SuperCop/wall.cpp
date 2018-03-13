//Alex Portolese and Sam Stein
//This file contains the coding to make the Wall work
#include "wall.h"

Wall::Wall(QWidget *parent, int xspawn)
{
    wall = new QPixmap("images/Wall/trashcan.png");

    gameWindow = parent->width();
    wallPosY = parent->height() - 140;
    wallPosX = gameWindow + 50 + xspawn;
//need to base this on these 2 plus a var for the wall location, then remove active var?
    picX = 32;
    picY = 40;
    active = true;
}//Initializes the variables for the Wall

Wall::~Wall()
{
    delete wall;
}//Destructor

void Wall::drawWall(QPainter &painter)
{
    QPen pen=painter.pen();
    pen.setStyle(Qt::NoPen);
    painter.setPen(pen);
    rectWall = new QRect(wallPosX, wallPosY, picX, picY);
    painter.drawRect(*rectWall);
    painter.drawTiledPixmap(*rectWall, *wall);
}//Draws the wall


void Wall::setWallPosX(int x)
{
    this->wallPosX = x;
}//Mutator

void Wall::setWallPosY(int y)
{
    this->wallPosY = y;
}//Mutator


void Wall::setActive(bool active)
{
    this->active = active;
}//Mutator

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

bool Wall::isActive()
{
    return active;
}//Accessor

