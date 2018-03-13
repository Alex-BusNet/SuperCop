//Alex Portolese and Sam Stein
//This file contains the coding to make the Controls window run.
#include "controls.h"
#include "ui_controls.h"

Controls::Controls(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Controls)
{
    ui->setupUi(this);
}//Runs Controls Window

Controls::~Controls()
{
    delete ui;
}//clears potential memory leaks
