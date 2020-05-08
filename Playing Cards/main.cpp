#include <iostream>
#include "Deck.h"
#include "Game.h"

int main()
{
	Game game(3);
	game.newRound();
	game.dealFlop();
	game.dealTurn();
	game.dealRiver();
	game.revealAllHands();

	//auto subdeck = std::vector<Card>();
	//subdeck.emplace_back(Card(1, Suit(2)));
	//subdeck.emplace_back(Card(10, Suit(2)));
	//subdeck.emplace_back(Card(11, Suit(1)));
	//subdeck.emplace_back(Card(10, Suit(3)));
	//subdeck.emplace_back(Card(2, Suit(3)));
	//subdeck.emplace_back(Card(10, Suit(1)));
	//subdeck.emplace_back(Card(11, Suit(2)));
	std::cout << game.getOpenCards() << std::endl;

	/*
	std::cout << Hand::hasStraight(subdeck) << std::endl;
	std::cout << Hand::hasFlush(subdeck) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 4) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 3) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 2) << std::endl;
	std::cout << Hand::hasTwoPairs(subdeck) << std::endl;
	std::cout << Hand::hasFullHouse(subdeck) << std::endl;*/

	std::cout << game << std::endl;

	//std::cout << Hand::getHighestHand(game.m_players[0].getHand(), game.getOpenCards()) << std::endl;
	//std::cout << Hand::getHighestHand(game.m_players[1].getHand(), game.getOpenCards()) << std::endl;
	//std::cout << Hand::getHighestHand(game.m_players[2].getHand(), game.getOpenCards()) << std::endl;

}
