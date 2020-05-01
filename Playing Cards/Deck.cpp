
#include <vector>     
#include "Deck.h"


Deck::Deck()
{
	for (int j = 0; j < 4; j++) {
		for (int i = 1; i < 14; i++) {
			m_deck.push_back(Card(i, Suit(j)));
		}
	}
}

Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::vector<Card> shuffledDeck;
	for (int size = remainingCards(); size > 0; size--) {
		auto pick = rand() % size;
		
		shuffledDeck.emplace_back(m_deck[pick]);

		m_deck.erase(m_deck.begin() + pick);
	}
	m_deck = shuffledDeck;

	//std::random_shuffle(m_deck.begin(), m_deck.end());
}

bool sortSortValuePrevious(Card card1, Card card2) {
	return (card1.m_sortValue < card2.m_sortValue);
}

void Deck::sort() {
	std::sort(m_deck.begin(), m_deck.end(), sortSortValuePrevious);
}

void Deck::printDeck()
{
	std::for_each(m_deck.begin(), m_deck.end(),
		[](Card card) {
			std::cout << card << std::endl;
	});
}

void Deck::printSortValues() {
	std::for_each(m_deck.begin(), m_deck.end(),
		[](Card card) {
		std::cout << card.m_sortValue << "\t";
	});
	std ::cout << std::endl;
}

int Deck::remainingCards()
{
	return m_deck.size();
}

Card Deck::dealCard()
{
	auto card = m_deck.front();
	m_deck.erase(m_deck.begin());
	return card;
}

Card Deck::peakTop()
{
	return m_deck.front();
}

std::vector<Card> Deck::getRemainingWithSuit(Suit suit)
{
	std::vector<Card> ret;
	/*std::for_each(m_deck.begin(), m_deck.end(),
		[](Card card, Suit suit, std::vector<Card> ret) {
		if (card.hasSuit(suit)) {
			ret.emplace_back(card);
		}
	});*/

	for (auto iter = m_deck.begin(); iter != m_deck.end(); iter++) {
		if (iter->hasSuit(suit)) {
			ret.emplace_back(*iter);
		}
	}
	return ret;
}

std::vector<Card> Deck::getRemainingWithValue(int value)
{
	std::vector<Card> ret;
	/*std::for_each(m_deck.begin(), m_deck.end(),
		[](Card card, int value, std::vector<Card> ret) {
		if (card.hasValue(value)) {
			ret.emplace_back(card);
		}
	});*/
	for (auto iter = m_deck.begin(); iter != m_deck.end(); iter++) {
		if (iter->hasValue(value)) {
			ret.emplace_back(*iter);
		}
	}
	return ret;
}

void Deck::print(std::vector<Card> cards)
{
	std::for_each(cards.begin(), cards.end(),
		[](Card card) {
		std::cout << card << std::endl;
	});
}
