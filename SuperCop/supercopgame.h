//Alex Portolese and Sam Stein
//This file contains the declarations for the Functional game.

#ifndef SUPERCOPGAME_H
#define SUPERCOPGAME_H

#include "levelbase.h"
#include "platform.h"
#include "player.h"
#include "wall.h"
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QPixmap>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>

#include <enemy.h>
#include <donut.h>
#include <vector>
#include <QElapsedTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
using namespace std;

namespace Ui {
class SuperCopGame;
}

class SuperCopGame : public QWidget
{
    Q_OBJECT


private:
    Ui::SuperCopGame *ui;

    enum keyPressed {NONE = 0, RIGHT = 1, UP = 2, DOWN = 3, LEFT = 4, PAUSE = 5};

    Player *player;
    LevelBase *lb;

    QWidget* parent;
    QTimer *timer;
    QTimer *keyTimer;
    QMessageBox *msg;
    QMessageBox *pbox;
    QFont *scoreFont;
    QFont *pausedFont;
    int picX,picY;
    int picHeight, picWidth;
    int lastKeyPress;
    int gamescore;
    int location;

    bool isUpPressed, isDownPressed, isLeftPressed, isRightPressed, gamePaused, showDevOpts;

    vector<Wall*>walls;
    vector<Platform*>platforms;
    vector<Donut*>donuts;
    vector<Enemy*>enemies;
    vector<int>donutspawn;
    vector<int>enemyspawn;
    vector<int>wallSpawn;
    vector<int>platSpawn;

    Donut *levelEnd;
    int moveSpeed;

    QPushButton *resume;
    QPushButton *exit;
    QLabel *paused;
    QHBoxLayout *hLayout;
    QHBoxLayout *hLayout2;
    QVBoxLayout *vLayout;
public:
    void paintEvent(QPaintEvent *e);
    explicit SuperCopGame(QWidget *parent = 0);
    ~SuperCopGame();

    void keyPressEvent(QKeyEvent *evt);
    void keyReleaseEvent(QKeyEvent *evt);
    void setLastKeyPress(int keyPress);
    void obstacleMovement();
    void setVecs();
    void setHighScores();
    void setMoveSpeed(int spd);
    void setShowDevOpts(bool devOpts);
signals:

public slots:
    void pollKey();
    void updateField();
    void resumeGame();
    void exitGame();

};

#endif // SUPERCOPGAME_H
