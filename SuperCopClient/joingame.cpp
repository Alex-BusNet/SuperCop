#include "joingame.h"
#include "ui_joingame.h"
#include <QCloseEvent>

JoinGame::JoinGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JoinGame)
{
    ui->setupUi(this);

    //Creates Socket Object
    //Socket sends and recieves data
    socket = new QTcpSocket(this);
}

JoinGame::~JoinGame()
{
    delete ui;
}//Prevents memory leaks

void JoinGame::setHostIP(QString address){ hostIP = address; }//Not currently doing anything

void JoinGame::closeEvent(QCloseEvent *e)
{
    socket->disconnectFromHost();
    e->accept();
}//'X' button Disconnects from server before closing the window

void JoinGame::on_pushButton_clicked()
{
    //Retrieves the host ip and player name from the message boxes
    hostIP=ui->HostIP->toPlainText();
    //qDebug() << "Player nickname: " << nickname;
    //qDebug() << "IP the player is trying to connect to: " << hostIP;

    //Initiates a connection to to the host IP and sends the nickname
    QByteArray sendData;
        sendData.append('connecting');
        //socket = new QTcpSocket(this);
        socket->connectToHost(hostIP, 5300);
        socket->waitForConnected(1000);
        //qDebug() << socket->state();
        if(socket->state() == QAbstractSocket::ConnectedState)
        {
            socket->write(sendData); //write the data itself
            socket->waitForBytesWritten();
        }
        else
        {
            qDebug() << socket->errorString();
        }

        //Connects the socket to slots for reading back data and reseting variables
        connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
        connect(socket, SIGNAL(disconnected()),this, SLOT(Disconnected()));

}

void JoinGame::Disconnected()
{//Resets the UI on disconnect
    qDebug() << "Disconnected";
}

void JoinGame::readyRead()
{//Triggered anytime the server sends data
    //Reads Socket Data sent by the server
    QString data;
    data = socket->readAll();
    //qDebug()<<data;

    //Splits the data based on ';'
    QString command = data.split(";").first();
    ui->EventLog->setText(ui->EventLog->toPlainText()+data);
    if(command=="CONNECTED"){
        //If the server is indicating a successful connection
        //Tells the Player what color their snake will be
        if(data.split(";").last()=="PLAYER1"){
        }
    }
    else if(command=="PLAYERLIST"){
        //If the server is sending an updated list of players
        //Sets the ui to display all connected players
        QStringList pieces = data.split( ";" );
        for(int i=0;i<pieces.length();i++){
            if(i==1){
               // ui->P1Name->setText(pieces.at(i));
            }
        }
    }
    else if(command=="STARTED"){
        //If the server is starting a game
        //Creates the game object
        //qDebug()<<"New Game";

        //Reads what player is assigned to that client and sets the starting movement direction
        int pnum=data.split(";").last().toInt();

    }
    else if(command=="UPDATE"){
        //If the server is updating the game (10x per second at least)
        //qDebug()<<"Recieved UPDATE";
        //Resets objects so they dont render in the old locations

        QStringList pieces = data.split( ";" );
        int onPart=0;
        for(int i=0;i<pieces.length();i++){
            //Sets which object is being updated
            if(pieces.value(i)=="APPLE"){
                onPart=0;
            }
        }
        //qDebug()<<"Send UPDATE";
        //Sends back its current direction to update the server
        QString dir=QString::number(1/*game2->getDirection()*/);
        QByteArray updateData;
        updateData.append("UPDATE;");
        updateData.append(dir);
        //qDebug() << socket->state();
        if(socket->state() == QAbstractSocket::ConnectedState)
        {
            socket->write(updateData); //write the data itself
            socket->waitForBytesWritten();
        }
        else
        {
            qDebug() << socket->errorString();
        }
    }
    else if(command=="END"){
        //If the server is indicating the game has ended
        //Displays who won to the player and disconnects from the server
        //qDebug()<<"End";
        socket->disconnectFromHost();
    }
}

void JoinGame::on_Jump_clicked()
{
    QByteArray updateData;
    updateData.append("Jump");
    //qDebug() << socket->state();
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(updateData); //write the data itself
        socket->waitForBytesWritten();
    }
    else
    {
        qDebug() << socket->errorString();
    }
}

void JoinGame::on_Left_clicked()
{

}

void JoinGame::on_Right_clicked()
{

}

void JoinGame::on_EndJump_clicked()
{
    QByteArray updateData;
    updateData.append("EndJump");
    //qDebug() << socket->state();
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(updateData); //write the data itself
        socket->waitForBytesWritten();
    }
    else
    {
        qDebug() << socket->errorString();
    }
}
