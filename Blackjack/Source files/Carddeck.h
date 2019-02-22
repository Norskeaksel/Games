#pragma once
#include "Cards.h"
#include "std_lib_facilities.h"
struct CardStruct {
	Suit s;
	Rank r;
}; 
string toString(CardStruct card);
string toStringShort(CardStruct card);
class CardDeck {
public:
	CardDeck() {
		for (int i = 1; i <= 4; i++) {
			for (int j = 2; j <= 14; j++) {
				Card  ny(static_cast<Suit>(i), static_cast<Rank> (j));
				cards.push_back(ny);
			}
		}
		currentCardIndex = 0;
	}
	vector<Card>getDeck() {
		return cards;
	}
	void swap(int a,int b) {
		Card one = cards[a];
		Card temp = one;
		cards[a] = cards[b];
		cards[b] = temp;
	}
	void shuffle() {
		srand(time(NULL));
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 52; i++) {
				int r = rand() % 52;
				swap(i, r);
			}
		}
	}
	void print() {
		for (auto i : cards) {
			string str= i.toString();
			cout << str<<endl;
		}
	}
	void printShort() {
		for (auto i : cards) {
			string str = i.toStringShort();
			cout<<str<<endl;
		}
	}
	const Card& drawCard() {
		//cout << "currentCardIndex " << currentCardIndex << endl;
		return cards[currentCardIndex++];
	}
private:
	vector<Card>cards;
	int currentCardIndex;
};
