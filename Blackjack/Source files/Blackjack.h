#pragma once
#include "std_lib_facilities.h"
#include <Windows.h>
#include "Cards.h"
#include "Carddeck.h"
class Blackjack {
public:
	Blackjack(bool isPlayer, CardDeck& deck) {
		for (int i = 0; i < 2; i++) {
			Sleep(500);
			hand.push_back(deck.drawCard());
			if (isPlayer)cout << "player: " << hand[i].toString() << endl;
		}
	}
	int handValue() {
		int svar = 0;
		int nrOfAces = 0;
		for (auto i : hand) {
			int r = i.getRank();
			if (r > 10 && r < 14) r = 10;
			if (r == 14) {
				nrOfAces++;
				r = 11;
			}
			svar += r;
			if (svar > 21 && nrOfAces) {
				nrOfAces--;
				svar -= 10;
			}
		}
		return svar;
	}
	void addCard(Card card) {
		hand.push_back(card);
	}
	vector<Card> getHand() { return hand; }
	//CardDeck getCardDeck() { return deck; }
	int handSize() { return hand.size(); }
private:
	vector<Card>hand;
};
void blackjack();
void anotherGame();