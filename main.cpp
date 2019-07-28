#include <iostream>
#include "deck.h"
#include "players.h"
#include "winner.h"
#include "commonFunction.h"

using namespace std;
using namespace winner;
using namespace Cf;

int main(int argc, char* argv[])
{
    srand(time(0));
    Deck decks;
    vector<int> rand_card = decks.Shuffle_Cards();

    int n;
    cout << " Number of players " << endl;
    cin >> n;
    vector<Players> player(n);
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
    for (int bet_turn = 1; bet_turn <= 4; bet_turn++){
        switch (bet_turn){

            case 2:{
                for (int i = 0; i < 3; i++){
                    board[i].Show = true;
                }
                break;
            }
            case 3:{
                board[3].Show = true;
                break;
            }
            case 4:{
                board[4].Show = true;
                break;
            }
        }
        clearScreen();
        PrintCard(player, board);
        for (int i = 0; i < n; i++){
            if (player[i].AskPeek(i) == true ){
                player[i].hands[0].Show = true;
                player[i].hands[1].Show = true;
                clearScreen();
                PrintCard(player, board);
                player[i].hands[0].Show = false;
                player[i].hands[1].Show = false;
                string checkDone;
                cout << "Press st when you done !" << endl;
                cin >> checkDone;
            }
            else {
                clearScreen();
                PrintCard(player, board);
            }
        }
    }


    clearScreen();
    for (int num = 0; num < n; num++){
        player[num].hands[0].Show = true;
        player[num].hands[1].Show = true;
        player[num].EvaluateCards(board);
    }


    cout << "SHOW DOWN" << endl;
    PrintCard(player, board);

     for (int num = 0; num < n; num++){

        cout << "PLAYER " << num+1 << endl;
        AnouncePrize(player[num].mainPoint);
    }

    DetermineWinner(player);


    /*_______________________________________________
    for (int i = 0; i < n; i++){
        cout << "PLAYER " << i + 1 << "'S CARDS "  << endl;
        for (int j = 0 ; j < 2; j++){
            player[i].hands[j].ShowCards();
            player[i].EvaluateCards(board);
        }
         AnouncePrize(player[i].mainPoint);
        cout << "______________________" << endl;
    }
    cout << "BOARD CARDS" << endl;
    for (int i = 0 ; i < 5; i++){
        board[i].ShowCards();
    }
    cout << "___________________" <<endl;

    cout << endl << endl ;
    DetermineWinner(player);
    ___________________________*/
    return 0;
}


