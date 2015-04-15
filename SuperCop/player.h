#ifndef Player_H
#define Player_H

#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include <QTimer>
#include <QPixmap>
#include <QKeyEvent>

class Player : public QObject
{

private:
    enum keyPressed {NONE = 0, RIGHT = 1, UP = 2, DOWN = 3, LEFT = 4};
    enum keyPress2 {W = UP, A = LEFT, S = DOWN, D = RIGHT};

    int posX;
    int posY;
    int sizeX;
    int sizeY;
    int frame;
    int lastActionPressed;
    QPixmap *image;

public:

    Player(QWidget *parent);
    ~Player();

    void drawPlayer(QPainter &painter);
    void changeImage(QString str);
    void playerScreenPos(QWidget *w);

    void jump();
    void roll();
    void run();
    void runInverted();
    void standBy();

    void setPosX(int x);
    void setPosY(int y);
    void setSizeX(int x);
    void setSizeY(int y);

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();
    int getFrame();

public slots:
    void playerAction(int action);
};

#endif // Player_H
