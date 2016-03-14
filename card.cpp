/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Source file of Card class
  **/
#include <iostream>
#include "card.h"

/**
   * @brief Card::getRank
   * @return
   */
  int Card::getRank() const{
     return ((this->index)%13+1);
  }
  int Card::get_index() const{
      return this->index;
  }
  /**
   * @brief Card::Card constructor
   * @param r
   */
  Card::Card(int r){
      index = r;
      int suit = index/13;
      int rank = index%13 + 1;

      if(suit==0){
          image_path_name = QString("://PNG-cards-1.3/%1_of_spades").arg(rank);
      }
      else if(suit==1){
          image_path_name = QString("://PNG-cards-1.3/%1_of_hearts").arg(rank);
      }
      else if(suit==2){
          image_path_name = QString("://PNG-cards-1.3/%1_of_diamonds").arg(rank);
      }
      else{
          image_path_name = QString("://PNG-cards-1.3/%1_of_clubs").arg(rank);
      }

  }

 /**
   * @brief Card::operator +
   * @param Card& c
   * @return
   */
  int Card:: operator+ (Card c) const{
     int rank1 = this->index%13 + 1;
     int rank2 = c.index % 13+1;
     return (rank1+rank2)%10;
  }

  /**
    * @brief Card::get_path_name
    * @return
    */
   QString Card::get_path_name(){
       return image_path_name;
   }
