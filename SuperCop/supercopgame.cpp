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


    paused=false;
    gamescore=0;
    gameover=0;
    enemy = new Enemy(this);
//    enemy->setSpeed(10);//We can use this as the difference between difficulties
}


SuperCopGame::~SuperCopGame()
{
    delete timer;
    delete player;
    delete keyTimer;


   // delete enemy;
}


void SuperCopGame::keyPressEvent(QKeyEvent *evt)
{
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

        gamescore++;

        break;
    case Qt::Key_W:
        isUpPressed = false;
        break;
    case Qt::Key_A:
        isLeftPressed = false;
        break;

    case Qt::Key_Escape:
        paused=true;
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
    if(isRightPressed || isLeftPressed || isUpPressed || isDownPressed||paused)
    {
        if(isRightPressed)
            lastKeyPress = 1;
        else if(isUpPressed)
            lastKeyPress = 2;
        else if(isDownPressed)
            lastKeyPress = 3;
        else if(isLeftPressed)
            lastKeyPress = 4;
        else if (isRightPressed)
            lastKeyPress = 0;
        else {
                QMessageBox pbox;
                pbox.setText("Paused");
                pbox.exec();
                paused = false;
        }

    }
    else
    {
        //Checks if none of the keys are pressed before checking if some of the keys are pressed.
        if(!isUpPressed && !isDownPressed && !isLeftPressed && !isRightPressed)
            lastKeyPress = lastKeyPress;
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
//     }
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


    enemy->drawEnemy(painter);
    gamescore++;


    //For debugging purposes
    QPen pen = QPen(Qt::red);
    painter.setPen(pen);
    painter.drawText(10,10, QString("Frame: %1").arg(QString::number(player->getFrame())));
    painter.drawText(20,20, QString("LastKeyPress: %1").arg(QString::number(lastKeyPress)));


    painter.drawText(10,30, QString("Score: %1").arg(QString::number(gamescore)));

    if(enemy->getPosX()<=player->getPosX()&&gameover==0&&enemy->getPosY()==player->getPosY()){
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
           //maybe add a window which declares "New High Score" in this case-time permitting
            }
            else if(secondscore<gamescore){
                   fifthscore=fourthscore;
                   fourthscore=thirdscore;
                   thirdscore=secondscore;
                   secondscore=gamescore;
            }
            else if(thirdscore<gamescore){
                   fifthscore=fourthscore;
                   fourthscore=thirdscore;
                   thirdscore=gamescore;
            }
            else if(fourthscore<gamescore){
                   fifthscore=fourthscore;
                   fourthscore=gamescore;
            }
            else if(fifthscore<gamescore){
                   fifthscore=gamescore;
            }

            ofstream setscores;
            setscores.open("../SuperCop/highscores.txt");

            setscores<<firstscore<<endl;
            setscores<<secondscore<<endl;
            setscores<<thirdscore<<endl;
            setscores<<fourthscore<<endl;
            setscores<<fifthscore<<endl;

            setscores.close();
            }//resets high scores if new high score acheived
    }
}
