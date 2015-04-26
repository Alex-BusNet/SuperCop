#include "platform.h"

Platform::Platform(QWidget *parent)
{
    gameWindow = parent->width();
    platform = new QPixmap("../SuperCop/Images/Wall/0.png");
    platformHeight = parent->height() - 160;
    platformPosX = gameWindow - (gameWindow / 6);
    platformLength = 48;
}

Platform::~Platform()
{
    delete platform;
}

void Platform::drawPlatform(QPainter &painter)
{
    rectPlat = new QRect(platformPosX, platformHeight, platformLength, 16);
    painter.drawRect(*rectPlat);
    QBrush brush;
    brush.setTexture(*platform);
    painter.fillRect(*rectPlat, brush);
}

void Platform::setPlatformPosX(int x)
{
    this->platformPosX = x;
}

int Platform::getPlatformPosX()
{
    return platformPosX;
}

int Platform::getPlatformPosY()
{
    return platformHeight;
}

int Platform::getPlatformEnd()
{
    return platformPosX + platformLength;
}

int Platform::getPlatformSizeX()
{
    return platformLength;
}

int Platform::getPlatformSizeY()
{
    return 16;
}
