#include <iostream>
#include <string>

#include "bot.hpp"



int main(void)
{
    
    Deck deck;
    board board;
    Hand hand;
    deck.randomize();
    board.draw(deck);
    board.draw(deck);
    board.draw(deck);
    hand.draw(deck);
    hand.draw(deck);
    std::cout << "DECK : " << std::endl;
    std::cout << deck << std::endl;
    std::cout << "BOARD : " << std::endl;
    std::cout <<  board << std::endl;
    std::cout << "HAND : " << std::endl;
    std::cout <<  hand << std::endl;


    return (0);
}
