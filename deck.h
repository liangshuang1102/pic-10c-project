/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Source file of Deck class
  **/
#ifndef DECK_H
#define DECK_H
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <QTimer>

class Deck
{   
public:
    //CONSTRUCTOR
    Deck();
    /*Public member used_card, stores all the cards that have been used
    If a blind card is replaced by player, then neither the blind card will not be stored
    in drawn_card nor the players can see it
    */
    std::vector<int> used_card;
    void remove_card(int i); //If one card has been drawn, then remove it from this deck.
    static int random(int range); //Random card generator
    void add_used_card(int i);
    int decksize();
    friend class Card;
private:
    std::vector<int> mydeck;
};

#endif // DECK_H
