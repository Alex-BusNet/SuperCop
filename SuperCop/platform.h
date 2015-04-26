#ifndef PLATFORM_H
#define PLATFORM_H

#include <QPainter>
#include <QWidget>
#include <QRect>


class Platform
{
private:
    QPixmap *platform;
    QRect *rectPlat;
    int picX, picY;
    int platformHeight, platformPosX, platformLength;
    int gameWindow;

public:
    Platform(QWidget *parent = 0);
    ~Platform();

    void drawPlatform(QPainter &painter);
    void setPlatformPosX(int x);

    int getPlatformPosX();
    int getPlatformPosY();
    int getPlatformEnd();
    int getPlatformSizeX();
    int getPlatformSizeY();
};

#endif // PLATFORM_H