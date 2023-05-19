#include "Blackjack.h"
void blackjack() {
	cout << "Lets play some Blackjack!\n";
	Sleep(1000);
	cout << "Try to get as close to 21 without going over 21. The dealer must draw until he has a sum of at least 17, afterwhich he cannot draw more.\n\n";
	Sleep(1500);
	int playerScore = 0;
	int dealerScore = 0;
	CardDeck deck;
	int c = 0;
	while (1) {
	gameLoopStart:;
		cout << "Player score: " << playerScore << " Dealer score: " << dealerScore << "\n\n";
		Sleep(1000);
		if (c++ % 5 == 0) {
			
			deck.shuffle();
			Sleep(1000);
		}

		cout << "dealer draws two cards and shows the first.\n";
		Blackjack dealer(false, deck);

		cout << "player draws two cards\n";
		Blackjack player(true, deck);
		cout << "player sum: " << player.handValue() << endl;
		Sleep(500);

		char in = 'y';
		while (in == 'y') {
			if (player.handValue() == 21) {
				Sleep(500);
				cout << "Blackjack! Player wins!\n\n";
				Sleep(1000);
				playerScore++;
				goto gameLoopStart;
			}
			cout << "Do you want to draw a card? y/n\n";
			cin >> in;
			if (in == 'y') {
				Card card = deck.drawCard();
				player.addCard(card);

				cout << card.toString() << endl;
				Sleep(500);
				cout << "player sum: " << player.handValue() << endl;
				Sleep(500);
			}
			else
				in = 'n';

			if (player.handValue() > 21) {
				cout << "Player loses.\n";
				dealerScore++;
				goto gameLoopStart;
			}
		}
		while (dealer.handValue() < 17) {
			Card card = deck.drawCard();
			dealer.addCard(card);
		}
		cout << "dealer cards:\n";
		for (auto i : dealer.getHand()) {
			Sleep(500);
			cout << i.toString() << endl;
		}
		Sleep(500);
		cout << "dealer sum: " << dealer.handValue() << endl;
		Sleep(500);
		if (player.handValue() > dealer.handValue() || dealer.handValue() > 21) {
			cout << "Player wins. Congrats\n";
			playerScore++;
		}
		else if (player.handValue() < dealer.handValue()) {
			cout << "dealer wins\n";
			dealerScore++;
		}
		else {
			cout << "It's a tie\n";
		}
		Sleep(500);
	}
}