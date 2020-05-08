#pragma once
#include "Deck.h"
#include "Player.h"

class Game
{
public:
	Game(int players);
	~Game();

	std::vector<Player> m_players;
	std::vector<Player>::iterator m_smallBlind;
	std::vector<Player>::iterator m_bigBlind;

	void newRound();
	void endRound();
	void dealFlop();
	void dealTurn();
	void dealRiver();
	void revealAllHands();
	Player getWinner();
	void movePot(Player player);
	int getPot();
	std::vector<Card> getOpenCards();

private: 
	void collectBigBlind();
	void collectSmallBlind();
	Deck m_deck;
	int m_pot;
	std::vector<Card> m_openCards;
	int m_blind;
};

std::ostream& operator<<(std::ostream& out, Game game);