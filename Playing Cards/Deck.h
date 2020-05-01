#pragma once
#include "Card.h"

#include <algorithm>  
#include <vector>

class Deck
{
public:
	Deck();
	~Deck();
	std::vector<Card> m_deck;

	void shuffle();
	void sort();
	void printDeck();
	void printSortValues();
	int remainingCards();
	Card dealCard();
	Card peakTop();
	
	std::vector<Card> getRemainingWithSuit(Suit suit);
	std::vector<Card> getRemainingWithValue(int value);

	void print(std::vector<Card>);
};

