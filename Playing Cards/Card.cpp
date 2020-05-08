#include "Card.h"

Card::Card(int getValue, Suit getSuit) {
	m_value = getValue;
	m_suit = getSuit;
	m_sortValue = m_value + m_suit * 13;
}

Card::Card(const Card &c) {
	m_value = c.m_value;
	m_suit = c.m_suit;
	m_sortValue = m_value + m_suit * 13;
}

Card::~Card() {}

bool Card::isValid() const { return (m_value >= ACE) && (m_value <= KING); }

std::string Card::toString() const { return m_value + " of " + m_suit; }

bool Card::sameSuit(const Card &c) { return c.m_suit == m_suit; }

bool Card::sameValue(const Card &c) { return c.m_value == m_value; }

bool Card::hasSuit(Suit getSuit) { return m_suit == getSuit; }

bool Card::hasValue(int getValue) { return m_value == getValue; }

bool Card::operator==(const Card &o) const {
	return ((m_value == o.m_value) && (m_suit == o.m_suit));
}

bool Card::operator!=(const Card &o) const { return !operator==(o); }

int Card::getValue() const { return m_value; }

Suit Card::getSuit() const { return m_suit; }

// int Card::sortValue() const {
//	return m_suit * 13 + m_value;
//}

static void print(Card &c) { std::cout << c; }

std::ostream &operator<<(std::ostream &out, const Card &card) {
	if (!card.isValid()) {
		out << "<Invalid>";
		return out;
	}
	int getValue = card.getValue();
	switch (card.getValue()) {
	case ACE:
		out << "Ace";
		break;
	case JACK:
		out << "Jack";
		break;
	case QUEEN:
		out << "Queen";
		break;
	case KING:
		out << "King";
		break;
	default:
		out << getValue;
		break;
	}
	out << " of ";
	switch (card.getSuit()) {
	case SPADES:
		out << "Spades";
		break;
	case CLUBS:
		out << "Clubs";
		break;
	case HEARTS:
		out << "Hearts";
		break;
	case DIAMONDS:
		out << "Diamonds";
		break;
	}
	return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<Card> cards) {
	if (cards.empty()) {
		out << "<Empty Vector>";
		return out;
	}
	for (unsigned int i = 0; i < cards.size(); i++) {
		out << cards[i] << "\t";
	}
	return out;
}

std::ostream &operator<<(std::ostream &out, const Suit &suit) {
	switch (suit) {
	case SPADES:
		out << "Spades";
		break;
	case CLUBS:
		out << "Clubs";
		break;
	case HEARTS:
		out << "Hearts";
		break;
	case DIAMONDS:
		out << "Diamonds";
		break;
	}
	return out;
}
