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
#include <vector>
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

    location=0;
    this->level1();
}


SuperCopGame::~SuperCopGame()
{
    delete timer;
    delete player;
    delete keyTimer;

    enemies.clear();
    donuts.clear();
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

        for(int i=0;i<donuts.size();i++){
            if(true==(*(donuts.at(i))).getActive()){
                (*(donuts.at(i))).setPosX((*(donuts.at(i))).getPosX()-5);
            }
        }
        location++;
    }

    if((-1 == player->getPlayerDirection()) && (player->getPosX() <= player->getLeftBound())&&0<location)
    {
        lb->setPlatformPosX(lb->getPlatformPosX() + 5);
        lb->setStairPosX(lb->getStairPosX() + 5);

        for(int i=0;i<donuts.size();i++){
            if(true==(*(donuts.at(i))).getActive()){
                (*(donuts.at(i))).setPosX((*(donuts.at(i))).getPosX()+5);
            }
        }
        location--;
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
    painter.drawText(10, 30, QString("location: %1").arg(QString::number(location)));


    for(int i=0;i<donuts.size();i++){

        if(5==location%40)
        {
            int j = location/40;
            if(j<donuts.size()){
            (*(donuts.at(j))).setActive(true);
            }
        }//spawns a donut every 40 location-units (1 LU = 5 pixels)starting at 5


        if(true==(*(donuts.at(i))).getActive()){
            (*(donuts.at(i))).drawDonut(painter);
        }
           if(true==(*(donuts.at(i))).getActive()){
                if(((*(donuts.at(i))).getPosX() <= player->getPosX()&&(*(donuts.at(i))).getPosX()+45>=player->getPosX())&&(*(donuts.at(i))).getPosY()==player->getPosY()){
                    (*(donuts.at(i))).setActive(false);
                    (*(donuts.at(i))).setPosX(-10000);//Donuts may technically be reactivated by going backward, but the player cannot go back past 0, and donuts will spawn waaaay back.
                    gamescore+=10;
                }//handles collisions with donut
            }

    }//Handles all cases of donut objects.


    for(int i=0;i<enemies.size();i++){


        if(25==location%40)
        {
            int j = location/40;
            if(j<enemies.size()){
                (*(enemies.at(j))).setActive(true);
            }
        }//spawns an enemy every 40 location-units (1 LU = 5 pixels)starting at 25

        if(true==(*(enemies.at(i))).getActive()){
            (*(enemies.at(i))).setPosX((*(enemies.at(i))).getPosX()-5);
            (*(enemies.at(i))).drawEnemy(painter);
        }//makes enemy not spawn immediately-and will allow for enemies to despawn later maybe?
        //enemy moves based on time, not player-basic AI

        if(((*(enemies.at(i))).getPosX() <= player->getPosX()&&(*(enemies.at(i))).getPosX()+35>=player->getPosX())&&(*(enemies.at(i))).getPosY()==player->getPosY()&&true==player->isJumping()){
            (*(enemies.at(i))).setActive(false);
            (*(enemies.at(i))).setPosX(-1000);
        }//Kills enemy if you jump on it

        if(((*(enemies.at(i))).getPosX() <= player->getPosX()&&(*(enemies.at(i))).getPosX()+35>=player->getPosX())&&(*(enemies.at(i))).getPosY()==player->getPosY()&&false==player->isJumping())
        {
             (*(enemies.at(i))).setPosY((*(enemies.at(i))).getPosY()-1);
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
        }//Handles all cases of enemy objects.
    }

void SuperCopGame::level1(){

    for(int i=0;i<5;i++){
        Enemy *enemy;
        enemy = new Enemy(this);
        enemies.push_back(enemy);
    }

    for(int i=0;i<5;i++){
        Donut *donut;
        donut= new Donut(this);
        donuts.push_back(donut);
    }
}//Initializes vectors
