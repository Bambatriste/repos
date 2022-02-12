#include <iostream>
#include <string>

#include "bot.hpp"



int main(void)
{

    // Card Kd(KING, DIAMOND, 0);
    // Card Qc(QUEEN, CLUB, 0);

    Deck deck;
    deck.randomize();
   // deck.display(std::cout);


    std::cout << deck << std::endl;
    //deck.display();
    //std::cout << deck << std::endl;


    return (0);
}
