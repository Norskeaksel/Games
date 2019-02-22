#pragma once
#include <string>
using namespace std;
enum Suit { CLUBS=1, DIAMONDS, HEARTS, SPADES };
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
string suitToString(Suit s);
string rankToString(Rank r);
class Card
{
public:
	Card(Suit suit, Rank rank) :
		rank(rank), suit(suit)
	{}
	void setSuit(Suit s) { suit = s; }
	void setRank(Rank r) { rank = r; }
	Suit getSuit() { return suit; }
	Rank getRank() { return rank; }
	bool isValid() {
		if (rank > 1 && rank <= 14 && suit > 0 && suit <= 4)
			return true;
		return false;
	}
	string toString() {
		if(isValid())
			return rankToString(rank) + " OF " + suitToString(suit);
		return "Ugyldig kort";
	}
	string toStringShort() {
			if (!isValid()) { return "Ugyldig kort"; }
			return suitToString(suit).substr(0, 1) + to_string(rank);
	}
private:
	Suit suit;
	Rank rank;
	bool valid;
};
