#ifndef DONUT_H
#define DONUT_H

#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

class Donut
{
public:
    Donut(QWidget *parent);
    ~Donut();

    void drawDonut(QPainter &painter);
    void changeImage(QString str);
    void eaten();
    void noteaten();

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
    QPixmap *donut;
    QTimer *moveTimer;
};

#endif // DONUT_H
