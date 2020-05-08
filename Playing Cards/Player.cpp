#include "Player.h"



Player::Player(int stash = 1000)
{
	m_stash = stash;
}

Player::Player()
{
	m_stash = 1000;
}


Player::~Player()
{
}

void Player::resetHand()
{
	handIsRevealed = false;
	m_hand = std::vector<Card>();
}

void Player::receiveCard(Card card)
{
	m_hand.emplace_back(card);
}

void Player::revealHand()
{
	handIsRevealed = true;
}

bool Player::hasRevealedHand()
{
	return handIsRevealed;
}

int Player::getPlayersStash()
{
	return m_stash;
}

std::vector<Card> Player::getHand()
{
	if(handIsRevealed)
		return m_hand;
	return std::vector<Card>();
}
void Player::bet(int bet)
{
	m_stash -= bet;
}
//
//Hand Player::getHighestHand(std::vector<Card> opencards)
//{
//	//return Hand::getHighestHand(m_hand, opencards);
//}
