#ifndef WALL_H
#define WALL_H

#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

class Wall
{
public:
    Wall(QWidget *parent);
    ~Wall();

    void drawWall(QPainter &painter);
    void changeImage(QString str);

    void setPosX(int x);
    void setPosY(int y);
    void setSizeX(int x);
    void setSizeY(int y);
    void setSpeed(int speed);

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();
    int getSpeed();

private:
    int speed;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    QPixmap *wall;
    QTimer *moveTimer;
};

#endif // WALL_H
