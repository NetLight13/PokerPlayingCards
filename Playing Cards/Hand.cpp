#include "Hand.h"
#include <algorithm>


Hand::Hand(HANDS hands, std::vector<Card> highestCards)
{
	m_handrank = hands;
	m_highestCards = highestCards;
}

Hand::Hand() {

}


Hand::~Hand()
{
}

bool sortValuePreviousAceHigh(Card card1, Card card2) {
	if (card1.getValue() == 1 && card2.getValue() != 1) {
		return true;
	}
	if (card2.getValue() == 1) {
		return false;
	}
	return (card1.getValue() > card2.getValue());
}

bool sortValuePreviousAceLow(Card card1, Card card2) {
	return (card1.getValue() > card2.getValue());
}

bool sortSuitPrevious(Card card1, Card card2) {
	return (card1.getSuit() > card2.getSuit());
}

bool Hand::isValid()
{
	return false;
}

Hand Hand::getHighestHand(std::vector<Card> playerhand, std::vector<Card> opencards)
{
	
	return Hand();
}

float Hand::chancesForPlayerPerspective(HANDS hand, std::vector<Card> playerhand, std::vector<Card> opencards)
{
	float ret = 0;
	if (opencards.empty()) {

	}

	return ret;
}

Hand Hand::hasStraight(std::vector<Card> cards)
{
	if (cards.size() < 5) {
		return Hand();
	}
	int values[7];

	//High Straight
	std::sort(cards.begin(), cards.end(), sortValuePreviousAceHigh);
	for (int i = 0; i < 7; i++) {
		values[i] = cards[i].getValue();
		if (values[i] == 1) {
			values[i] = 14;
		}
	}
	bool valueFound = false;
	for (unsigned int i = 0; i < cards.size() - 4; i++) {
		std::vector<Card> ret;
		ret.emplace_back(cards[i]);
		for (int diff = 1; diff < 5; diff++) {
			valueFound = false;
			for (unsigned int j = 1; j < 7 - i && !valueFound; j++) {
				if (values[i + j] - values[i] == -diff) {
					valueFound = true;
					ret.emplace_back(cards[i + j]);
					if (ret.size() == 5) {
						return Hand(HANDS(4), ret);
					}
				}
			}
		}
	}

	//Low Straight with ACE as 1
	std::sort(cards.begin(), cards.end(), sortValuePreviousAceLow);
	for (int i = 0; i < 7; i++) {
		values[i] = cards[i].getValue();
	}
	for (unsigned int i = 0; i < cards.size() - 4; i++) {
		std::vector<Card> ret;
		ret.emplace_back(cards[i]);
		for (int diff = 1; diff < 5; diff++) {
			valueFound = false;
			for (unsigned int j = 1; j < 7 - i && !valueFound; j++) {
				if (values[i + j] - values[i] == -diff) {
					valueFound = true;
					ret.emplace_back(cards[i + j]);
					if (ret.size() == 5) {
						return Hand(HANDS(4), ret);
					}
				}
			}
		}
	}

	return Hand();
}

Hand Hand::hasFlush(std::vector<Card> cards)
{
	if (cards.size() < 5) {
		return Hand();
	}
	Suit suits[7];
	std::sort(cards.begin(), cards.end(), sortValuePreviousAceHigh);
	for (unsigned int i = 0; i < 7 && i < cards.size(); i++) {
		suits[i] = cards[i].getSuit();
	}

	for (unsigned int i = 0; i < cards.size() - 4; i++) {
		std::vector<Card> ret;
		ret.emplace_back(cards[i]);
		for (unsigned int j = 1; j < 7 - i; j++) {
			if (suits[i] == suits[i + j]) {
				ret.emplace_back(cards[i + j]);
				if (ret.size() >= 5) {
					Hand::fillHand(ret, cards);
					return Hand(HANDS(5), ret);
				}
			}
		}
	}
	return Hand();
}

Hand Hand::hasNOfAKind(std::vector<Card> cards, unsigned int n)
{
	if (cards.size() < n || n < 2 || n > 4) {
		return Hand();
	}
	int values[7];
	std::sort(cards.begin(), cards.end(), sortValuePreviousAceHigh);
	for (unsigned int i = 0; i < 7 && i < cards.size(); i++) {
		values[i] = cards[i].getValue();
	}
	unsigned int sameValueFound = 1;
	for (unsigned int i = 0; i < cards.size() - (n - 1); i++) {
		sameValueFound = 1;
		std::vector<Card> ret;
		ret.emplace_back(cards[i]);

		for (unsigned int j = 1; j < cards.size() - i; j++) {
			if (values[i + j] == values[i]) {
				sameValueFound++;
				ret.emplace_back(cards[i + j]);

				if (sameValueFound >= n) {

					Hand::fillHand(ret, cards);

					switch (n)
					{
					case 2:
						return Hand(HANDS(1), ret);
						break;
					case 3:
						return Hand(HANDS(3), ret);
						break;
					case 4:
						return Hand(HANDS(7), ret);
						break;
					default:
						break;
					}
				}
			}
		}
	}
	return Hand();
}

void Hand::fillHand(std::vector<Card> &ret, std::vector<Card> &cards)
{
	if (ret.size() >= 5) {
		return;
	}
	bool whilereset = true;
	for (unsigned int c = 0; whilereset && c < cards.size(); c++) {
		bool brake = true;
		for (unsigned int r = 0; brake && r < ret.size(); r++) {
			if (cards[c] == ret[r]) {
				brake = false;
			}
		}
		if (brake) {
			ret.emplace_back(cards[c]);
			if (ret.size() >= 5) {
				whilereset = false;
			}
		}
	}
}

Hand Hand::hasTwoPairs(std::vector<Card> cards)
{
	if (cards.size() < 4) {
		return Hand();
	}
	int values[7];
	std::sort(cards.begin(), cards.end(), sortValuePreviousAceHigh);
	for (unsigned int i = 0; i < 7 && i < cards.size(); i++) {
		values[i] = cards[i].getValue();
	}
	bool firstPairFound = true;
	for (unsigned int i = 0; i < cards.size() - 1; i++) {
		firstPairFound = false;
		std::vector<Card> ret;
		ret.emplace_back(cards[i]);
		for (unsigned int j = 1; j < cards.size() - i; j++) {
			if (values[i + j] == values[i]) {
				firstPairFound = true;
				ret.emplace_back(cards[i + j]);
				if (firstPairFound) {
					bool secondPairFound = false;
					for (unsigned int s = 2; s < cards.size() - i; s++) {
						for(unsigned int t = 1; t < cards.size() - i - s; t++)
						if (values[i + t + s] == values[i + s]) {
							secondPairFound = true;
							ret.emplace_back(cards[i + s]);
							ret.emplace_back(cards[i + s + t]);
							if (secondPairFound) {
								Hand::fillHand(ret, cards);
								return Hand(HANDS(2), ret);
							}
						}
					}
				}
			}
		}
	}
	return Hand();
}

std::string valueToString(int value) {
	switch (value) {
	case ACE: return "Ace"; break;
	case JACK: return "Jack"; break;
	case QUEEN: return "Queen"; break;
	case KING: return "King"; break;
	default: return std::to_string(value);
		break;
	}
}

std::ostream & operator<<(std::ostream & out, const Hand & hand)
{
	if (hand.m_highestCards.empty() || !hand.m_highestCards[0].isValid() || hand.m_handrank < 1 || hand.m_handrank > 9) {
		out << "<Invalid>";
		return out;
	}

	HANDS handrank = hand.m_handrank;

	switch (handrank)
	{
	case HIGHESTCARD:
		out << "Highest Card: ";
		break;
	case PAIR:
		out << "Pair of " << valueToString(hand.m_highestCards[0].getValue());
		break;
	case DOUBLEPAIR:
		out << "Two Pairs of " << valueToString(hand.m_highestCards[0].getValue()) << " and " << valueToString(hand.m_highestCards[2].getValue());
		break;
	case THREEOFAKIND:
		out << "Three of " << valueToString(hand.m_highestCards[0].getValue());
		break;
	case STRAIGHT:
		out << "Straight " << valueToString(hand.m_highestCards[4].getValue()) << " to " << valueToString(hand.m_highestCards[0].getValue());
		break;
	case FLUSH:
		out << "Flush of " << hand.m_highestCards[0].getSuit();
		break;
	case FULLHOUSE:
		out << "Full House of " << valueToString(hand.m_highestCards[0].getValue()) << " and " << valueToString(hand.m_highestCards[3].getValue());
		break;
	case FOUROFAKIND:
		out << "Four of " << valueToString(hand.m_highestCards[0].getValue());
		break;
	case STRAIGHTFLUSH:
		out << "Straight Flush of " << hand.m_highestCards[0].getSuit() << " " << valueToString(hand.m_highestCards[4].getValue()) << " to " << valueToString(hand.m_highestCards[0].getValue());
		break;
	case ROYALFLUSH:
		out << "Royal Flush of " << hand.m_highestCards[0].getSuit();
		break;
	default:
		break;
	}
	out << ":\t" << hand.m_highestCards;

	return out;
}
