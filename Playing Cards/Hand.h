#pragma once
#include "Card.h"
#include <vector>

enum HANDS {
		HIGHESTCARD,
		PAIR,
		DOUBLEPAIR,
		THREEOFAKIND,
		STRAIGHT,
		FLUSH,
		FULLHOUSE,
		FOUROFAKIND,
		STRAIGHTFLUSH,
		ROYALFLUSH,
	};

class Hand
{
	
public:
	HANDS m_handrank;
	std::vector<Card> m_highestCards;

private:
	Hand();
	Hand(HANDS hands, std::vector<Card> highestCards);
	Hand(const Hand& hand);
	
public:
	~Hand();
	static Hand getHighestHand(std::vector<Card> playerhand, std::vector<Card> opencards);
	static float chancesForPlayerPerspective(HANDS hand, std::vector<Card> playerhand, std::vector<Card> opencards);
	static Hand hasStraight(std::vector<Card> cards);
	static Hand hasFlush(std::vector<Card> cards);
	static Hand hasNOfAKind(std::vector<Card> cards, unsigned int n);
	static void fillHand(std::vector<Card> &ret, std::vector<Card> &cards);
	static Hand hasTwoPairs(std::vector<Card> cards);
	static Hand hasFullHouse(std::vector<Card> cards);
	static Hand hasStraightFlush(std::vector<Card> cards);
	static Hand hasRoyalFlush(std::vector<Card> cards);
	bool isValid();
	bool operator<(const Hand & h) const;
	bool operator>(const Hand & h) const;
	bool operator==(const Hand & h) const;
};

std::ostream& operator<<(std::ostream& out, const Hand& hand);