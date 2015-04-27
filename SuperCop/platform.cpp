//Alex Portolese and Sam Stein
//This file contains the coding to make the platform functional.
#include "platform.h"

Platform::Platform(QWidget *parent)
{
    gameWindow = parent->width();
    platform = new QPixmap("../SuperCop/Images/Wall/0.png");
    platformHeight = parent->height() - 160;
    platformPosX = gameWindow +20;
    platformLength = 48;
    active=false;
}//initializes the platform variables


Platform::~Platform()
{
    delete platform;
}//Destructor

void Platform::drawPlatform(QPainter &painter)
{
    rectPlat = new QRect(platformPosX, platformHeight, platformLength, 16);
    painter.drawRect(*rectPlat);
    QBrush brush;
    brush.setTexture(*platform);
    painter.fillRect(*rectPlat, brush);
}//Draws the platform

void Platform::setPlatformPosX(int x)
{
    this->platformPosX = x;
}//Mutator

int Platform::getPlatformPosX()
{
    return platformPosX;
}//Accessor

int Platform::getPlatformPosY()
{
    return platformHeight;
}//Accessor

int Platform::getPlatformEnd()
{
    return platformPosX + platformLength;
}//Accessor

int Platform::getPlatformSizeX()
{
    return platformLength;
}//Accessor

int Platform::getPlatformSizeY()
{
    return 16;
}//Accessor

bool Platform::getActive()
{
    return active;
}//Accessor

void Platform::setActive(bool act)
{
    active=act;
}//Mutator

