#pragma once
#include <vector>
#include "Card.h"
#include "Hand.h"

class Player
{
private:
	bool handIsRevealed = false;
	std::vector<Card> m_hand;
	int m_stash;

public:
	Player();
	Player(int stash);
	~Player();

	void resetHand();
	void receiveCard(Card card);
	void addCoins(int coins);
	void revealHand();
	bool hasRevealedHand();
	int getPlayersStash();
	std::vector<Card> getHand();

//	Hand getHighestHand(std::vector<Card> opencards);

	//Actions
	void raise(int raise);
	int check();
	int call(int call);
	int fold();
	void bet(int bet);

};

