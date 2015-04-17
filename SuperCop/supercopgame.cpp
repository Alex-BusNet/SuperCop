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
#include "enemy.h"
#include "donut.h"
#include "wall.h"


SuperCopGame::SuperCopGame(QWidget *parent) :
    QWidget(parent)
{
    srand(time(0));
    player = new Player(this);

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
//    connect(keyTimer, SIGNAL(timeout()), this, SLOT(pollKey()));
    keyTimer->start();

    isUpPressed = false;
    isDownPressed = false;
    isLeftPressed = false;
    isRightPressed = false;

    lastKeyPress = 0;



    playerstopped=false;
    spawntimer=0;
    donut = new Donut(this);
    paused=false;
    gamescore=0;
    gameover=0;
    enemy = new Enemy(this);
    wall = new Wall(this);
//    enemy->setSpeed(10);//We can use this as the difference between difficulties
}


SuperCopGame::~SuperCopGame()
{
    delete timer;
    delete player;
    delete keyTimer;

    delete enemy;
    delete donut;
    delete wall;
}//clears potential memory leaks


void SuperCopGame::keyPressEvent(QKeyEvent *evt)
{
    playerstopped=false;
    switch(evt->key())
    {
    case Qt::Key_D:
        isRightPressed = true;
        break;
    case Qt::Key_S:
        isDownPressed = true;
        break;
    case Qt::Key_W:
        isUpPressed = true;
        break;
    case Qt::Key_A:
        isLeftPressed = true;
        break;


    case Qt::Key_Escape:
         paused = true;


    default:
        break;
    }
}


void SuperCopGame::keyReleaseEvent(QKeyEvent *evt)
{
    switch(evt->key())
    {
    case Qt::Key_D:
        isRightPressed = false;
        break;
    case Qt::Key_S:
        isDownPressed = false;
        break;
    case Qt::Key_W:
        isUpPressed = false;
        break;
    case Qt::Key_A:
        isLeftPressed = false;
        break;

    case Qt::Key_Escape:
        paused=false;
        break;

    default:
        break;
    }
}


void SuperCopGame::setLastKeyPress(int key)
{
    this->lastKeyPress = key;
}




void SuperCopGame::pollKey()
{
    //Checks if any of the keys are pressed.
    if(isRightPressed || isLeftPressed || isUpPressed || isDownPressed||paused||playerstopped)
    {
        if(isRightPressed)
            lastKeyPress = 1;
        else if(isUpPressed)
            lastKeyPress = 2;
        else if(isDownPressed)
            lastKeyPress = 3;
        else if(isLeftPressed)
            lastKeyPress = 4;


        else if(playerstopped)
            lastKeyPress = 0;
        else if(paused){
                QMessageBox pbox;
                pbox.setText("Paused");
                pbox.exec();
                paused = false;
        }


        else
            lastKeyPress = 0;
    }
    else
    {
        //Checks if none of the keys are pressed before checking if some of the keys are pressed.
        if(!isUpPressed && !isDownPressed && !isLeftPressed && !isRightPressed)
            if(3 != lastKeyPress&&2!=lastKeyPress){
                    lastKeyPress=lastKeyPress;
            }
            else if (2==lastKeyPress) {
                lastKeyPress=0;
            }
            else{
                lastKeyPress=1;
            }//Keeps roll motion from looping
        else if(!isUpPressed && !isDownPressed && !isLeftPressed)
            lastKeyPress = 1;
        else if(!isUpPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = 2;
        else if(!isUpPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = 3;
        else if(!isUpPressed && !isDownPressed && !isRightPressed)
            lastKeyPress = 4;
        else
            lastKeyPress = 0;
     }
}


void SuperCopGame::updateField()
{
    pollKey();
    player->playerAction(lastKeyPress);
    this->update();
}


void SuperCopGame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    player->drawPlayer(painter);

    spawntimer++;
    donut->drawDonut(painter);
    enemy->drawEnemy(painter);
    wall->drawWall(painter);

    if((spawntimer)%150==0){
    enemy->setSpeed(7);
    }//periodically spawns a new enemy-mostly placeholder for level design

    if((spawntimer)%30==0){
    donut->setSpeed(4);
    }//periodically spawns a new donut-mostly placeholder for level design

    if((((donut->getPosX())<=player->getPosX())&&((donut->getPosX()+30)>=player->getPosX()))||(((donut->getPosX())<=(player->getPosX()+50))&&((donut->getPosX()+30)>=(player->getPosX()+50)))){
      if (((donut->getPosY()+donut->getSizeY())>=player->getPosY())&&(donut->getPosY()<=player->getPosY())){
        gamescore+=5;
        donut->eaten();
      }
    }//runs if player hits a donut
    if(donut->getPosX()<=0){
        donut->noteaten();
    }//runs if donut leaves the left side of the screen

    if(enemy->getPosX()<=0){
        enemy->setSpeed(0);
        enemy->setPosX(700);
    }//runs if enemy leaves the left side of the screen

    if((spawntimer)%70==0){
    wall->setSpeed(4);
    }//periodically spawns a new wall-mostly placeholder for level design
    if(wall->getPosX()<=0){
        wall->setSpeed(0);
        wall->setPosX(700);
    }//runs if enemy leaves the left side of the screen

    if(player->getPosX()>=(this->width()-player->getSizeX())||0>=player->getPosX()){
        playerstopped=true;
        }//Stops player if they reach the edge on their own(Exception: see if statement below this)

    if(wall->getPosX()<=player->getPosX()+51&&wall->getPosX()>=player->getPosX()&&wall->getPosY()==player->getPosY()){
       player->setPosX(wall->getPosX()-51);

       if(-30>player->getPosX()){
           gameended();
           player->setPosX(700);

       }//Ends game if player gets pushed out of the screen by a wall
    }

    if((enemy->getPosX()<=(player->getPosX()))&&((enemy->getPosX()+80)>=(player->getPosX()))&&(enemy->getPosY()==player->getPosY())&&(0==gameover)&&(0==player->getjumpframe())){
       gameended();
    }//Ends game if player hits an enemy


    //For debugging purposes
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);
    painter.drawText(10,10, QString("Frame: %1").arg(QString::number(player->getFrame())));
    painter.drawText(20,20, QString("LastKeyPress: %1").arg(QString::number(lastKeyPress)));


    painter.drawText(10,30, QString("Score: %1").arg(QString::number(gamescore)));
}


void SuperCopGame::gameended()
{
    timer->stop();
    QMessageBox mbox;
    mbox.setText("Game Over");
    mbox.exec();
    gameover=1;

    ifstream scoreset;//may be necessary to make seperate high score pages for each difficulty setting
    scoreset.open("../SuperCop/highscores.txt");
    int scores;

    if(scoreset.is_open()){

        scoreset>>scores;
        int firstscore=scores;
        scoreset>>scores;
        int secondscore=scores;
        scoreset>>scores;
        int thirdscore=scores;
        scoreset>>scores;
        int fourthscore=scores;
        scoreset>>scores;
        int fifthscore=scores;
        scoreset.close();

        if(firstscore<gamescore){
               fifthscore=fourthscore;
               fourthscore=thirdscore;
               thirdscore=secondscore;
               secondscore=firstscore;
               firstscore=gamescore;

               QMessageBox sbox;
               sbox.setText("New High Score: "+ QString::number(gamescore));
               sbox.exec();

        }//If new Higehest score
        else if(secondscore<gamescore){
               fifthscore=fourthscore;
               fourthscore=thirdscore;
               thirdscore=secondscore;
               secondscore=gamescore;
        }//If new second Higehest score
        else if(thirdscore<gamescore){
               fifthscore=fourthscore;
               fourthscore=thirdscore;
               thirdscore=gamescore;
        }//If new third Higehest score
        else if(fourthscore<gamescore){
               fifthscore=fourthscore;
               fourthscore=gamescore;
        }//If  fourth Higehest score
        else if(fifthscore<gamescore){
               fifthscore=gamescore;
        }//If new fifth Higehest score

        ofstream setscores;
        setscores.open("../SuperCop/highscores.txt");

        setscores<<firstscore<<endl;
        setscores<<secondscore<<endl;
        setscores<<thirdscore<<endl;
        setscores<<fourthscore<<endl;
        setscores<<fifthscore<<endl;

        setscores.close();
        }//resets high scores if new high score acheived

}//concludes game ending sequence
