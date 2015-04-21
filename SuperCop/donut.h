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

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();

private:
    int windowwidth;
    int posX;
    int posY;
    int sizeX;
    int sizeY;
    QPixmap *donut;
};

#endif // DONUT_H
