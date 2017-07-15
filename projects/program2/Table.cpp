#include <iostream>
#include "Table.h"
#include "Deck.h"
#include <vector>

using namespace std;

// Constructor for Table, sets the ante and number of seats at the table.
Table::Table(int num_seats, int ante) {
	this->max_seats = num_seats;
	this->ante = ante;
	seats = 0;
	ingame = {};
	losers = {};
}

// checks to see if the table is empty.
bool Table::emptySeat() {
	if (seats < max_seats) return true;
	return false;
}

// a full round at the table. compares each player's card and returns all the losers. the winner is saved.
vector<Player> Table::playRound() {
	losers.clear();
	if (ingame.size() == 0) return losers;
	Deck deck;
	deck.shuffle();
	// bets for all players and gives each player a card.
	for (int i = 0; i < seats; i++) {
		ingame[i].bet(ante);
		ingame[i].hand = deck.draw();
	}
	winner = ingame[0];
	for (int i = 1; i < seats; i++ ) {
		// if the next value is better than the winner, they become the temporary winner
		if (ingame[i].hand.getValue() > winner.hand.getValue()) {
			losers.push_back(winner);
			winner = ingame[i];
		}
		else {
			// if the winner and player have the same value card, it checks suit to break a tie.
			if (ingame[i].hand.getValue() == winner.hand.getValue()) {
				if (winner.hand.getSuit() < ingame[i].hand.getSuit()) {
					losers.push_back(winner);
					winner = ingame[i];
				}
				else {
					losers.push_back(ingame[i]);
				}
			}
			else {
				losers.push_back(ingame[i]);
			}
		}
	}
	// the winner is awarded, and kept in the game. Others are returned.
	winner.collectWinnings(ante * seats);
	ingame.clear();
	ingame.push_back(winner);
	seats = 1;
	return losers;
}

// adds a new player to the table, and increases the number of seats.
void Table::addPlayer(Player p) {
	seats++;
	ingame.push_back(p);
}

// prints the winner of the table.
void Table::printWinner() {
	cout << "\nThe winner is: " << winner.getName() << " with $" << winner.getBudget()<< "!" << endl;
}

// returns the winner of the table.
Player Table::getWinner() {
	return winner;
}
