#include "Carddeck.h"

string toString(CardStruct card) {
	return rankToString(card.r) + " OF " + suitToString(card.s);
}
string toStringShort(CardStruct card) {
	return suitToString(card.s).substr(0, 1) + to_string(card.r);
}