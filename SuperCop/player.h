//Alex Portolese and Sam Stein
//This file contains the declarations for the Player class.
#ifndef Player_H
#define Player_H

#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QRect>

class Player : QObject
{

private:
    enum keyPressed {NONE = 0, RIGHT = 1, UP = 2, DOWN = 3, LEFT = 4, PAUSE = 5};
    enum direction {WEST = -1, STAND = 0, EAST = 1};
    bool rolling, jumping, moveLeft, moveRight, ascend, upPressed, pause;
    bool onGround, playerOnWall, playerOnPlatform, wallCollided;
    int rectPosX, rectPosY, rectSizeX, rectSizeY;
    int posX, posY;
    int sizeX, sizeY;
    int frame;
    int leftBound, rightBound;
    int ground, speedX;
    int lastActionPressed;
    int playerDirection;
    QPixmap *image;
public:

    Player(QWidget *parent);
    ~Player();

    void drawPlayer(QPainter &painter);
    void changeImage(QString str);
    void playerScreenPos();

    void jump();
    void roll();
    void run();
    void runInverted();
    void standBy();
    void pausePlayer();

    void setPosX(int x);
    void setPosY(int y);
    void setSizeX(int x);
    void setSizeY(int y);
    void setOnGround(bool onGround);
    void setSpeedY(int y);
    void setJumping(bool jump);
    void setOnWall(bool onWall);
    void setOnPlatform(bool onPlat);
    void setWallCollided(bool wallCollided);
    void setSpeedX(int spd);
    void setRectPosX(int x);
    void setRectPosY(int y);

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();
    int getFrame();
    int getLeftBound();
    int getRightBound();
    int getPlayerDirection();
    int getGround();
    int getSpeedY();
    int getRectPosX();
    int getRectPosY();
    int getRectSizeX();
    int getRectSizeY();

    bool isRolling();
    bool isJumping();
    bool isMoveRight();
    bool isMoveLeft();
    bool isOnGround();
    bool isAscending();
    bool isOnPlatform();
    bool isOnWall();
    bool isWallCollided();

public slots:
    void playerAction(int action);
};

#endif // Player_H
