/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Cpp file of player class
  **/
#include "player.h"
/* Define function load_card()
 * @param int random (to indicated the rank of the card that will be created
 * @param int index (to indicate which card will be created, 0 for mycard, 1 for opcard
*/
void player::load_card(int random,int index){
    if (index==0){
       mycard = Card(random);}
    else{
       opcard = Card(random);
    }
}

/*Define my getter function
 * @param int n
 * return a card object
 */
Card player::get_card(int n){
    if(n == 0){
        return mycard;
    }
    else{
        return opcard;
    }
}


/* Computer asks about blind card
 * @param player a
 * return 0 if blind card is ok
 * return 1 if blind card needs to be replaced
 * return 2 if it is equal to the value
 */
int player:: ask_blind_card_action(player a){
    int handcard = (mycard.getRank())%10;
    int num= ((a.opcard).getRank())%10;
    switch(handcard){
    case 1:{
        if(num<8){
            return 0;
        }
        else if(num>8){
            return 1;
        }
        else{
            return 2;
        }
    }
    case 2:{
        if(num<7){
            return 0;
        }
        else if(num>7){
            return 1;
        }
        else{
            return 2;
        }
    }
    case 3:{
        if(num<6){
            return 0;
        }
        else if(num>6){
            return 1;
        }
        else{
            return 2;
        }
    }
    case 4:{
        if(num<5){
            return 0;
        }
        else if(num>5){
            return 1;
        }
        else{
            return 2;
        }
    }
    case 5:{
        if(num<4){
            return 0;
        }
        else if(num>4){
            return 1;
        }
        else{
            return 2;
        }
    }
    case 6:{
        if(num<=3){
            return 2;
        }
        else {
            return 1;
        }
    }
    case 7:{
        if(num<=2){
            return 2;
        }
        else{
            return 1;
        }
    }
    case 8:{
        if(num>5){
            return 0;
        }
        else{
            return 1;
        }
    }
    case 9:{
        if(num<=4){
            return 0;
        }
        else{
            return 1;
        }
    }
    case 0:{
        if(num<5){
            return 0;
        }
        else if(num>5){
            return 1;
        }
        else{
            return 2;
        }
    }
   }
}

/**
 * @brief player::double_bet_action
 * set player's double_bet action
 * @param a
 */
void player::double_bet_action(int a){
    if(a==2){
        double_status = true;
    }
    else{
        double_status = false;
    }
}
/**
 * @brief player::get_double_status
 * get player's double status
 * @return
 */
bool player::get_double_status(){
    if(double_status){
        return true;
    }
    else
        return false;
}
