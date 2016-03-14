/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Header file of GameCentralWidget class
  **/
#ifndef GAMECENTRALWIDGET_H
#define GAMECENTRALWIDGET_H
#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <iostream>
#include <QLabel>
#include "Card.h"
#include "deck.h"
#include <chrono>
#include <random>
#include <string>
#include "player.h"
namespace Ui {
class GameCentralWidget;
}

class GameCentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameCentralWidget(QWidget *parent =0, int n=1);
    ~GameCentralWidget();
    void clear_last_hand();
    void deal_card();
public slots:
    void set_QLineEdit();
    void read_input();
    void change_blind_card();
    void display_pushbutton3();
    void display_pushbutton3_forbB2();
    void display_result();
    void begin_game();
    void double_bet();

   // void update_hand();
private:
    Ui::GameCentralWidget *ui;
    std::vector<QPixmap*> card_images;
    //std::vector<Card> myhand;
    //std::vector<Card> computer_hand;
    player computer;
    player human;
    Deck gamedeck;
    const QPixmap* caocao_image;
    const QPixmap* kongming_image;
    const QPixmap* pokerback_image;
    const QPixmap* caocao_double_image;
    const QPixmap* kongming_double_image;
    int step_count = 0;
    int round_count = 1;
    int score = 0;
    int level ;
};

#endif // GAMECENTRALWIDGET_H
