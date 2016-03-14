/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Header file of Card class
  **/
#ifndef CARD_H
#define CARD_H
#include <string>
#include <QString>

//Declare Card class
class Card{
public:
    Card():index(1){};

    //Constructor
    Card(int r);

    //Getter the rank of card:(1,2,3....12,13)
    int getRank() const;
    //Getter
    int get_index() const;
    QString get_path_name();

    //Overload operator +
    //return the ones digit of the sum of 2 cards
    int operator+ (Card c) const;
private:
    int index;
    QString image_path_name;

};
#endif // CARD_H
