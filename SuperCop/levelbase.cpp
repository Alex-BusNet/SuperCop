//Alex Portolese and Sam Stein
//This file contains the coding to make the floor work
#include "levelbase.h"
#include <QDebug>

LevelBase::LevelBase(QWidget *parent)
{
    floor = new QPixmap("Images/Wall/road.png");
    floorStart = parent->height() - 100;
    picX = 133;//doesnt do anything?
    picY = 32;//doesnt do anything?
    floorLength = parent->width() / 28.0;
    gameWindow = parent->width();

    generateLevel = new QTimer();
    generateLevel->setInterval(50);
}//Initializes the variables for the floor

LevelBase::~LevelBase()
{
    delete floor;
    delete generateLevel;
}//Destructor


void LevelBase::drawLevelBase(QPainter &painter)
{
    rect = new QRect(0, floorStart, gameWindow, 40);
    painter.drawRect(*rect);
    QBrush brush;
    brush.setTexture(*floor);
    painter.fillRect(*rect, brush);
}//Draws the floor


