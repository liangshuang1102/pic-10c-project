/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  This file implements the welcome screen~
  **/
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tutorial_begin() {
    tboard = new tutorialwidget(this);
    this->setCentralWidget(tboard);
    this->show();
}

void MainWindow::easy_game_begin() {
    board = new GameCentralWidget(this,1);
    //level = 1;
    this->setCentralWidget(board);
    this->show();
}

void MainWindow::medium_game_begin() {
    board = new GameCentralWidget(this,2);
    this->setCentralWidget(board);
    this->show();
}


void MainWindow::back_to_menu(){
       QWidget* temp = this->centralWidget();
       temp->setParent(NULL);
       ui->setupUi(this);
}
