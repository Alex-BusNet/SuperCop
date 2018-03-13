//Alex Portolese and Sam Stein
//This file contains the coding to make the enemies functional.
#include "enemy.h"
#include <QDebug>

Enemy::Enemy(QWidget *parent)
{

    posX = parent->width() ;//spawns at left edge
    posY = parent->height() - 140;//spawns at platform height
    sizeX = 40;//width of enemy(image)
    sizeY = 40;//height of enemy(image)
    robot = new QPixmap("Images/Enemy/enemy0.png");
    active=false;//doesnt spawn until triggered
    direction=0;//goes left by default
}//initializes the enemy variables

Enemy::~Enemy()
{
    delete robot;

}//Destructor

void Enemy::drawEnemy(QPainter &painter)
{
    painter.drawPixmap(posX, posY, sizeX, sizeY, *robot);
}//Draws the enemy image

void Enemy::changeImage(QString str)
{
    delete robot;
    robot = new QPixmap(str);
}//allow for the enemy image to be changed


void Enemy::setPosX(int x)
{
    posX=x;
}//Mutator

void Enemy::setPosY(int y)
{
    posY=y;
}//Mutator

void Enemy::setSizeX(int x)
{
    sizeX=x;
}//Mutator

void Enemy::setSizeY(int y)
{
    sizeY=y;
}//Mutator

int Enemy::getPosX()
{
    return posX;
}//Accessor

int Enemy::getPosY()
{
    return posY;
}//Accessor

int Enemy::getSizeX()
{
    return sizeX;
}//Accessor

int Enemy::getSizeY()
{
    return sizeY;
}//Accessor

bool Enemy::getActive()
{
    return active;
}//Mutator

void Enemy::setActive(bool act)
{
    active=act;
}//Accessor

void Enemy::setDirection(int direc)
{
    direction=direc;
    switch(direction)
    {
    case RIGHT:
        changeImage("Images/Enemy/enemy1.png");
        break;
    case LEFT:
        changeImage("Images/Enemy/enemy0.png");
        break;
    }
}//Mutator

int Enemy::getDirection()
{
    return direction;
}//Accessor
