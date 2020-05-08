#include "Game.h"



Game::Game(int players)
{
	for (int i = 0; i < players; i++) {
		m_players.emplace_back(Player());
	}
	m_smallBlind = m_players.begin();
	m_bigBlind = m_players.begin() + 1;
	m_blind = 1;
}


Game::~Game()
{
}

void Game::newRound()
{
	collectSmallBlind();
	collectBigBlind();
	m_deck = Deck();
	m_deck.shuffle();
	for (unsigned int i = 0; i < m_players.size() * 2; i++) {
		m_players[i % m_players.size()].receiveCard(m_deck.dealCard());
	}

	//std::for_each(m_players.begin(), m_players.end(),
	//	[](Player player, Deck m_deck) {
	//	player.receiveCard(m_deck.dealCard());
	//});

	//std::for_each(m_players.begin(), m_players.end(),
	//	[](Player player, Card card = m_deck.dealCard()) {
	//	player.receiveCard(card);
	//});


}

void Game::endRound()
{
	m_smallBlind++;
	if (m_smallBlind == m_players.end()) {
		m_smallBlind = m_players.begin();
		m_blind *= 2;
	}
	m_bigBlind++;
	if (m_bigBlind == m_players.end())
		m_bigBlind = m_players.begin();
}

void Game::dealFlop()
{
	m_openCards.emplace_back(m_deck.dealCard());
	m_openCards.emplace_back(m_deck.dealCard());
	m_openCards.emplace_back(m_deck.dealCard());
}

void Game::dealTurn()
{
	m_openCards.emplace_back(m_deck.dealCard());
}

void Game::dealRiver()
{
	m_openCards.emplace_back(m_deck.dealCard());
}

void Game::revealAllHands()
{
	//std::for_each(m_players.begin(), m_players.end(), [&](Player player) {
	//	player.revealHand();
	//});

	for (unsigned int i = 0; i < m_players.size(); i++) {
		m_players[i].revealHand();
	}
}

int Game::getPot()
{
	return m_pot;
}

std::vector<Card> Game::getOpenCards()
{
	return m_openCards;
}

void Game::collectBigBlind()
{
	m_bigBlind->bet(m_blind * 2);
	m_pot += m_blind * 2;
}

void Game::collectSmallBlind()
{
	m_smallBlind->bet(m_blind);
	m_pot += m_blind;
}

std::ostream & operator<<(std::ostream & out, Game game)
{
	auto openCards = game.getOpenCards();
	//std::for_each(game.m_players.begin(), game.m_players.end(), [](Player player, std::ostream out, std::vector<Card> openCards) {
	//	out << "Stash: " << player.getPlayersStash() << " Hand: " << player.getHand() << std::endl;
	//	out << Hand::getHighestHand(player.getHand(), openCards) << std::endl;
	//});
	for (unsigned int i = 0; i < game.m_players.size(); i++) {
		out << "Stash: \t" << game.m_players[i].getPlayersStash() << " \tHand: \t" << game.m_players[i].getHand() << std::endl;
		if(game.m_players[i].hasRevealedHand())
			out << Hand::getHighestHand(game.m_players[i].getHand(), openCards) << std::endl;
		out << std::endl;
	}

	return out;
}
