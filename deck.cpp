/**
  Name:Shuang Liang
  UID:304193710
  HW10 PIC10C
  Source file of Deck class
  **/
#include "deck.h"

/**
 * @brief Deck::Deck Constructor
 */
Deck::Deck()
{
    //Initilize the vector
  for(size_t i= 0; i < 52; ++i){
      mydeck.push_back(i);
  }
}
/**
 * @brief Deck::remove_card
 * @param i
 */
void Deck::remove_card(int i){
    //Remove cards at index i
    std::vector<int>::iterator position = std::find(mydeck.begin(), mydeck.end(), i);
    if (position != mydeck.end())  //Check if it's a valid position
        mydeck.erase(position);
}

void Deck::add_used_card(int i){
    used_card.push_back(i);
}

/**
 * @brief Deck::random
 * @param range
 * @return
 */
int Deck::random(int range){
    //Generate Random Numbers
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0,range);
   return distribution(generator);
}

/**
 * @brief Deck::decksize
 * @return
 */
int Deck::decksize(){
    return mydeck.size();
}
