#include <iostream>
#include "Deck.h"
#include "Hand.h"

int main()
{
	Deck deck;
	// auto subdeck = std::vector<Card>(deck.m_deck.begin() + 11, deck.m_deck.begin() + 11 + 7);
	auto subdeck = std::vector<Card>();
	subdeck.emplace_back(Card(1, Suit(2)));
	subdeck.emplace_back(Card(10, Suit(2)));
	subdeck.emplace_back(Card(1, Suit(1)));
	subdeck.emplace_back(Card(12, Suit(2)));
	subdeck.emplace_back(Card(2, Suit(3)));
	subdeck.emplace_back(Card(10, Suit(1)));
	subdeck.emplace_back(Card(11, Suit(2)));
	std::cout << subdeck << std::endl;
	std::cout << Hand::hasStraight(subdeck) << std::endl;
	std::cout << Hand::hasFlush(subdeck) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 4) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 3) << std::endl;
	std::cout << Hand::hasNOfAKind(subdeck, 2) << std::endl;
	std::cout << Hand::hasTwoPairs(subdeck) << std::endl;
}
