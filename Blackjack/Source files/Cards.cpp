#include "std_lib_facilities.h"
#include "Cards.h"

using namespace std;

string suitToString(Suit s) {
	switch (s)
	{
	case CLUBS:
		return "CLUBS";
		break;
	case DIAMONDS:
		return "DIAMONDS";
		break;
	case HEARTS:
		return "HEARTS";
		break;
	case SPADES:
		return "SPADES";
		break;
	default:
		return "JOKER";
		break;
	}

}
string rankToString(Rank r) {
	switch (r)
	{
	case TWO:
		return "TWO";
		break;
	case THREE:
		return "THREE";
		break;
	case FOUR:
		return "FOUR";
		break;
	case FIVE:
		return "FIVE";
		break;
	case SIX:
		return "SIX";
		break;
	case SEVEN:
		return "SEVEN";
		break;
	case EIGHT:
		return "EIGHT";
		break;
	case NINE:
		return "NINE";
		break;
	case TEN:
		return "TEN";
		break;
	case JACK:
		return "JACK";
		break;
	case QUEEN:
		return "QUEEN";
		break;
	case KING:
		return "KING";
		break;
	case ACE:
		return "ACE";
		break;
	default:
		return "JOKER";
		break;
	}
}



/*

}*/