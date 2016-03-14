/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Header file of Player class
  **/
#ifndef PLAYER_H
#define PLAYER_H
#include <card.h>
class player{
public:
    player(){};
    void load_card(int random, int index);
    Card get_card(int n);
    int ask_blind_card_action(player a);
    void double_bet_action(int a);
    bool get_double_status();
private:
    Card mycard; //This is my hand card
    Card opcard; //This is opponent's blind card
    bool double_status = false; //This bool stores if player doubles his/her bet
};

#endif // PLAYER_H
