#include <iostream>
#include "deck.h"
#include "players.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    Deck decks;
    vector<int> rand_card = decks.Shuffle_Cards();

    int n;
    cout << " Number of players " << endl;
    cin >> n;
    Players player[n];
    vector<Cards>board;
    int current_cards_pos = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2; j++){
            player[i].hands.push_back(decks.NewDeck[rand_card[current_cards_pos]]);
            current_cards_pos++;
        }
    }
    for (int i = 0; i < 5; i++){
        board.push_back(decks.NewDeck[rand_card[current_cards_pos]]);
        current_cards_pos++;
    }
    for (int i = 0; i < n; i++){
        cout << "PLAYER " << i + 1 << "'S CARDS "  << endl;
        for (int j = 0 ; j < 2; j++){
            player[i].hands[j].ShowCards();
            player[i].EvaluateCards(board);
        }
        cout << "______________________" << endl;
    }
    cout << "BOARD CARDS" << endl;
    for (int i = 0 ; i < 5; i++){
        board[i].ShowCards();
    }
    cout << "___________________" <<endl;


}


