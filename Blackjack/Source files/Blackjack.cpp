#include "Blackjack.h"
/*char anotherGame() {
	char again;
	chrono::seconds dura(1);
	cout << "Want to play again? y/n\n";
	cin >> again;
	return again;
}*/
void blackjack() {
	char again = 'y';
	cout << "Lets play some Blackjack!\n";
	Sleep(2000);
	while (again == 'y') {
		CardDeck deck;
		deck.shuffle();
		cout << "player draws two cards\n";
		Blackjack player(true,deck), dealer(false,deck);
		cout << "player sum: " << player.handValue() << endl;// << "dealer hand size: " << dealer.handSize() << endl;
		char in = 'y';
		while (in == 'y') {
			cout << "Do you want to draw a card? y/n\n";
			cin >> in;
			if (in == 'y') {
				Card card = deck/*player.getCardDeck()*/.drawCard();
				player.addCard(card);
				cout << card.toString() << endl << "player sum: " << player.handValue()<<endl;
			}
			else in = 'n';
			if (player.handValue() > 21)
				break;
		}
		if (player.handValue() == 21 && dealer.handValue() != 21) {
			cout << "BLACKJACK! Player wins\n";
			Sleep(1000);
			cout << "Want to play again? y/n\n";
			cin >> again;
		}
		else if (player.handValue() > 21) {
			cout << "Player loses.\n";
			Sleep(1000);
			cout << "Want to play again? y/n\n";
			cin >> again;
		}
		else {

			while (dealer.handValue() < 17) {
				Card card = deck/*player.getCardDeck()*/.drawCard();
				dealer.addCard(card);
			}
			cout << "dealer cards:\n";
			for (auto i : dealer.getHand()) {
				Sleep(500);
				cout << i.toString() << endl;
			}
			cout << "dealer sum: " << dealer.handValue()<<endl;
			if (player.handValue() > dealer.handValue()|| dealer.handValue()>21) {
				cout << "Player wins. Congrats\n";
				Sleep(1000);
				cout << "Want to play again? y/n\n";
				cin >> again;
			}
			else if (player.handValue() < dealer.handValue()) {
				cout << "dealer wins\n";
				Sleep(1000);
				cout << "Want to play again? y/n\n";
				cin >> again;
			}
			else {
				cout << "It's a tie\n";
				Sleep(1000);
				cout << "Want to play again? y/n\n";
				cin >> again;
			}
		}
	}
}