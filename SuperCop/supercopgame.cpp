#include "supercopgame.h"
#include "player.h"
#include <QGraphicsScene>
#include <QQmlComponent>
#include <QGraphicsObject>
#include <QKeyEvent>
#include <QDebug>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

#include <donut.h>

SuperCopGame::SuperCopGame(QWidget *parent) :
    QWidget(parent)
{
    srand(time(0));
    player = new Player(this);
    lb = new LevelBase(this);

    //Sets the Game Background (Currently Temporary)
    QPixmap bkgnd("../SuperCop/Images/background_temp.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    timer = new QTimer();
    timer->setInterval(40);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateField()));
    timer->start();

    keyTimer = new QTimer();
    keyTimer->setInterval(5);
    connect(keyTimer, SIGNAL(timeout()), this, SLOT(pollKey()));
    keyTimer->start();

    isUpPressed = false;
    isDownPressed = false;
    isLeftPressed = false;
    isRightPressed = false;

    lastKeyPress = 0;

    gamescore=0;
    enemy = new Enemy(this);
    isenemy=false;
    donut= new Donut(this);
    eventNumber=0;
//    lvbs[3]=NULL;
}


SuperCopGame::~SuperCopGame()
{
    delete timer;
    delete player;
    delete keyTimer;
}


void SuperCopGame::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_Right:
        isRightPressed = true;
        break;
    case Qt::Key_Down:
        isDownPressed = true;
        break;
    case Qt::Key_Up:
        isUpPressed = true;
        break;
    case Qt::Key_Left:
        isLeftPressed = true;
        break;
    default:
        break;
    }
}


void SuperCopGame::keyReleaseEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_Right:
        isRightPressed = false;
        break;
    case Qt::Key_Down:
        isDownPressed = false;
        break;
    case Qt::Key_Up:
        isUpPressed = false;
        break;
    case Qt::Key_Left:
        isLeftPressed = false;
        break;
    default:
        break;
    }
}


void SuperCopGame::setLastKeyPress(int key)
{
    this->lastKeyPress = key;
}

void SuperCopGame::setPlatformX(int x)
{
    lb->setPlatformPosX(x);
}

void SuperCopGame::obstacleMovement()
{
    if((1 == player->getPlayerDirection()) && (player->getPosX() + player->getSizeX()) >= player->getRightBound())
    {
        lb->setPlatformPosX(lb->getPlatformPosX() - 5);
        lb->setStairPosX(lb->getStairPosX() - 5);

        donut->setPosX(donut->getPosX()-5);
    }

    if((-1 == player->getPlayerDirection()) && (player->getPosX() <= player->getLeftBound()))
    {
        lb->setPlatformPosX(lb->getPlatformPosX() + 5);
        lb->setStairPosX(lb->getStairPosX() + 5);

        donut->setPosX(donut->getPosX()+5);
    }
}

void SuperCopGame::physics()
{
    //Platform Collision Detection
    if((player->getPosX() >= lb->getPlatformPosX()) && (player->getPosX() <= lb->getPlatformEnd()))
    {
        if(player->getPosY() < lb->getPlatformPosY())
        {
            player->setPosY(lb->getPlatformPosY() - 43);
            player->setCollided(true);
        }
        else
        {

            if(player->getPosY() < player->getGround())
            {
                player->setCollided(false);
            }
            else
            {
                player->setCollided(true);
            }
        }
    }

    else
    {
        if(player->getPosY() <= player->getGround())
        {
            player->setCollided(false);
        }
        else
        {
            player->setCollided(true);
        }
    }
        //Stair Collision Detection
        //    if(player->getPosX() >= lb->getStep1PosX() && player->getPosX() < lb->getStep2PosX())
        //    {
        //        if(player->getPosY() < lb->getStep1PosY())
        //        {
        //            player->setPosY(lb->getStep1PosY());
        //            player->setCollided(true);
        //        }
        //        else
        //        {
        //            player->setPosY(player->getPosY());
        //            player->setCollided(true);
        //        }
        //    }
        //    else if(player->getPosX() >= lb->getStep2PosX() && player->getPosX() < lb->getStep3PosX())
        //    {
        //        if(player->getPosY() < lb->getStep2PosY())
        //        {
        //            player->setPosY(lb->getStep2PosY());
        //            player->setCollided(true);
        //        }
        //        else
        //        {
        //            player->setPosY(player->getPosY());
        //            player->setCollided(true);
        //        }
        //    }
        //    else if(player->getPosX() >= lb->getStep3PosX() && player->getPosX() < lb->getStep4PosX())
        //    {
        //        if(player->getPosY() < lb->getStep3PosY())
        //        {
        //            player->setPosY(lb->getStep3PosY());
        //            player->setCollided(true);
        //        }
        //        else
        //        {
        //            player->setPosY(player->getPosY());
        //            player->setCollided(true);
        //        }
        //    }
        //    else if(player->getPosX() >= lb->getStep4PosX() && player->getPosX() < lb->getStep4PosX() + 16)
        //    {
        //        if(player->getPosY() < lb->getStep4PosY())
        //        {
        //            player->setPosY(lb->getStep4PosY());
        //            player->setCollided(true);
        //        }
        //        else
        //        {
        //            player->setPosY(player->getPosY());
        //            player->setCollided(true);
        //        }
        //    }
        //    else
        //    {
        //        player->setPosX(player->getPosX());
        //        player->setCollided(true);
    //    }
}


int SuperCopGame::getPlatformX()
{
    return lb->getPlatformPosX();
}

void SuperCopGame::pollKey() //DO NOT MODIFY. Code Works now.
{
    //Checks if any of the keys are pressed.
    if(isDownPressed)
        lastKeyPress = 3;
    else if(isUpPressed)
        lastKeyPress = 2;
    else if(isRightPressed)
        lastKeyPress = 1;
    else if(isLeftPressed )
        lastKeyPress = 4;
    else
    {
        //Checks if none of the keys are pressed before checking if some of the keys are pressed.
        if(!isUpPressed && !isDownPressed && !isLeftPressed && !isRightPressed)
        {
            if(3 == lastKeyPress && player->isRolling())
                lastKeyPress = 3;
            else if(2 == lastKeyPress && player->isJumping())
                lastKeyPress = 2;
            else if(1 == lastKeyPress && player->isMoveRight())
                lastKeyPress = 1;
            else if (4 == lastKeyPress && player->isMoveLeft())
                lastKeyPress = 4;
            else
                lastKeyPress = 0;
        }
        else
            lastKeyPress = 0;
    }
}

void SuperCopGame::updateField()
{
    player->playerAction(lastKeyPress);
    obstacleMovement();
    physics();
    this->update();
}

void SuperCopGame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    player->drawPlayer(painter);
    lb->drawLevel(painter);

    //For debugging purposes
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);
    painter.drawText(10, 10, QString("Frame: %1").arg(QString::number(player->getFrame())));
    painter.drawText(10, 20, QString("LastKeyPress: %1").arg(QString::number(lastKeyPress)));

    if(true==isenemy){
    enemy->setPosX(enemy->getPosX()-5);
    }//enemy moves based on time, not player-basic AI

    donut->drawDonut(painter);

    if((1 == player->getPlayerDirection()) && (player->getPosX() + player->getSizeX()) >= player->getRightBound())
    {
       isenemy=true;
    }//makes enemy's initialization dependant on where in the level the player is

    if(true==isenemy){
       enemy->drawEnemy(painter);
    }//makes enemy not spawn immediately-and will allow for enemies to despawn later maybe?

    if((donut->getPosX() <= player->getPosX()&&donut->getPosX()+45>=player->getPosX())&&donut->getPosY()==player->getPosY()){
       donut->eaten();
       gamescore+=10;
     //  level1(e);
    }//handles collisions with donut

    if (-35==enemy->getPosX()){
        enemy->setPosX(this->width());
    }//resets enemy if it exits the screen- this is placeholder for level design

    if((enemy->getPosX() <= player->getPosX()&&enemy->getPosX()+35>=player->getPosX())&&enemy->getPosY()==player->getPosY())
    {
        enemy->setPosY(enemy->getPosY()-1);
        timer->stop();
        QMessageBox mbox;
        mbox.setText("Game Over");
        mbox.exec();
        ifstream scoreset;
        scoreset.open("../SuperCop/highscores.txt");
        int scores;

        if(scoreset.is_open()){

            scoreset >> scores;
            int firstscore = scores;
            scoreset >> scores;
            int secondscore = scores;
            scoreset >> scores;
            int thirdscore = scores;
            scoreset >> scores;
            int fourthscore = scores;
            scoreset >> scores;
            int fifthscore = scores;
            scoreset.close();

            if(firstscore < gamescore)
            {
                   fifthscore = fourthscore;
                   fourthscore = thirdscore;
                   thirdscore = secondscore;
                   secondscore = firstscore;
                   firstscore = gamescore;

                   QMessageBox sbox;
                   sbox.setText("New High Score: "+ QString::number(gamescore));
                   sbox.exec();
            }
            else if(secondscore < gamescore)
            {
                   fifthscore = fourthscore;
                   fourthscore = thirdscore;
                   thirdscore = secondscore;
                   secondscore = gamescore;
            }
            else if(thirdscore < gamescore)
            {
                   fifthscore = fourthscore;
                   fourthscore = thirdscore;
                   thirdscore = gamescore;
            }
            else if(fourthscore < gamescore)
            {
                   fifthscore = fourthscore;
                   fourthscore = gamescore;
            }
            else if(fifthscore<gamescore)
            {
                   fifthscore = gamescore;
            }

            ofstream setscores;
            setscores.open("../SuperCop/highscores.txt");

            setscores << firstscore << endl;
            setscores << secondscore << endl;
            setscores << thirdscore << endl;
            setscores << fourthscore << endl;
            setscores << fifthscore << endl;

            setscores.close();
            }//resets high scores if new high score acheived

         }
    }

void SuperCopGame::level1(QPaintEvent *e)
{
//    qDebug()<<"level1";
//    QPainter paint(this);
//    if (0==eventNumber){
//       LevelBase *stair1=new LevelBase(this);
//       stair1->setStairPosX(this->width());
//       stair1->drawStairs(paint);
//       qDebug()<<"stairs";

//    }
//    if(1==eventNumber){
//        LevelBase *platform1=new LevelBase(this);
//        platform1->setPlatformPosX(this->width());
//        platform1->drawPlatform(paint);
//        qDebug()<<"plat";
//    }
//    eventNumber++;
}
