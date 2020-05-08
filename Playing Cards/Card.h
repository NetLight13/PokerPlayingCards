#pragma once
#include <string>
#include <iostream>
#include <vector>

enum Suit {
	SPADES,
	CLUBS,
	HEARTS,
	DIAMONDS
};

const static int ACE = 1;
const static int JACK = 11;
const static int QUEEN = 12;
const static int KING = 13;

class Card
{
public:

	
	Card(int getValue, Suit getSuit);
	Card(const Card& c);
	~Card();

	bool isValid() const;
	std::string toString() const;

	bool sameSuit(const Card& c);
	bool sameValue(const Card& c);
	bool hasSuit(Suit getSuit);
	bool hasValue(int getValue);
	bool operator==(const Card & o) const;
	bool operator!=(const Card & o) const;
	int getValue() const;
	Suit getSuit() const;
	int m_sortValue;

private:
	int m_value;
	Suit m_suit;
};

std::ostream& operator<<(std::ostream& out, const Card& card);
std::ostream& operator<<(std::ostream& out, const std::vector<Card> cards);
std::ostream& operator<<(std::ostream& out, const Suit& suit);
