#include "player.h"
#include "supercopgame.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>


Player::Player(QWidget *parent)
{
    posX = parent->width() / 3;
    posY = parent->height() - 220;
    leftbound = 0;
    rightbound=parent->width();
    defaultY = parent->height() - 220;
    sizeX = 50;
    sizeY = 85;
    image = new QPixmap("../SuperCop/Images/Running/Run0_1.png");
    frame = 0;
    lastActionPressed = 0;
    jumpframe=0;

//    playerScreenPos(parent);
}


Player::~Player()
{
    delete image;
}//clears potential memory leaks

void Player::drawPlayer(QPainter &painter)
{
    painter.drawPixmap(posX, posY, sizeX, sizeY, *image);
}


void Player::changeImage(QString str)
{
    delete image;
    image = new QPixmap(str);
}


void Player::playerScreenPos(QWidget *w)
{

}


void Player::playerAction(int action)
{
    //If the new direction does not match the previous direction, reset the frame counter to zero.
    if(0==jumpframe){
        if(2==lastActionPressed){
            lastActionPressed = action;
//            action=0;
         }
         else if(action != lastActionPressed)
         {
            frame = 0;
            lastActionPressed = action;
         }
    }
    else {
        action=2;
    }


    //Checks which direction is being called then runs the appropriate function
    switch (action)
    {
    case RIGHT:
        run();
        break;
    case UP:
        jump();
        break;
    case DOWN:
        roll();
        break;
    case LEFT:
        runInverted();
        break;
    case NONE:
        standBy();
        break;
    }
}


void Player::jump()
{
    jumpframe++;

    if(0 < jumpframe && 9 > jumpframe)
    {
        QString imagePath = QString("../SuperCop/Images/Rolling/Roll%1.png").arg(QString::number(jumpframe));
        changeImage(imagePath);

        if (5>jumpframe){
            posY-=25;
        }
        else if (5<=jumpframe){
            posY+=25;
        }

        if (posX <= rightbound-sizeX)
        posX+=10;

    }
        else{
        jumpframe = 0;
        changeImage("../SuperCop/Images/Running/Run0_1.png");
        lastActionPressed = 2;
        }
}//Jumping


void Player::roll()
{
    frame++;

    if(0 < frame && 9 > frame && posX <= rightbound-sizeX)
    {


        QString imagePath = QString("../SuperCop/Images/Rolling/Roll%1.png").arg(QString::number(frame));
        changeImage(imagePath);

        posX++;//rolling is faster than running right now
    }
    else {
        //After one loop, return the player to normal size and continue running to the right.
        sizeX = 50;
        sizeY = 86;
        frame = 0;
        changeImage("../SuperCop/Images/Running/Run0_1.png");
        lastActionPressed = 0;
    }
}//rolling


void Player::run()
{
    frame++;
    QString imagePath = QString("../SuperCop/Images/Running/Run0_%1.png").arg(frame);

    if(0 < frame && 4 > frame && posX <= rightbound-sizeX)
    {

        changeImage(imagePath);
        posX+=7;//running has a speed. 7 is an arbitrary standard speed for "moving" objects for now.
    }
    else
    {
        frame = 0;
        changeImage("../SuperCop/Images/Running/Run0_1.png");
    }

}


void Player::runInverted()
{
    frame++;

    QString imagePath = QString("../SuperCop/Images/Running/Run1_%1.png").arg(frame);

    if(0 < frame && 4 > frame && posX >= leftbound)
    {
        changeImage(imagePath);
        posX-=7;//running has a speed. 7 is an arbitrary standard speed for "moving" objects for now.
    }
    else
    {
        frame = 0;
        changeImage("../SuperCop/Images/Running/Run1_1.png");
    }
}


void Player::standBy()
{
    if(1 == lastActionPressed||0==lastActionPressed)
        changeImage("../SuperCop/Images/Running/Run0_1.png");


    if(4 == lastActionPressed)
        changeImage("../SuperCop/Images/Running/Run1_1.png");
}


int Player::getFrame()
{
    return frame;
}//Accessor

int Player::getjumpframe()
{
    return jumpframe;
}//Accessor

void Player::setPosX(int x)
{
    posX=x;
}//Mutator

void Player::setPosY(int y)
{
    posY=y;
}//Mutator

void Player::setSizeX(int x)
{
    sizeX=x;
}//Mutator

void Player::setSizeY(int y)
{
    sizeY=y;
}//Mutator

int Player::getPosX()
{
    return posX;
}//Accessor

int Player::getPosY()
{
   return posY;
}//Accessor

int Player::getSizeX()
{
  return sizeX;
}//Accessor

int Player::getSizeY()
{
    return sizeY;
}//Accessor
