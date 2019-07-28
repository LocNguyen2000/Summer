#include "deck.h"
#include "players.h"
#include "winner.h"

int dealer, small_blind, big_blind;

namespace Cf{

    void SetBlind(int d, int num_player){
        small_blind = d + 1;
        big_blind = d + 2;
        if (small_blind > num_player){
            small_blind -= num_player;
        }
        if (big_blind > num_player){
            big_blind -= num_player;
        }
    }

    void PrintCard(vector<Players>p, vector<Cards>b){
       for (int i = 0; i < p.size(); i++){
            cout << "PLAYER " << i + 1 << "'S CARDS "  << endl;
            for (int j = 0 ; j < 2; j++){
                if(p[i].hands[j].Show == true){
                    p[i].hands[j].ShowCards();
                }
                else {
                    p[i].hands[j].HideCards();
                }
            }
            cout << "______________________" << endl;

       }
        cout << "BOARD CARDS" << endl;
        for (int i = 0 ; i < 5; i++){
            if (b[i].Show == true){
                b[i].ShowCards();
            }
            else{
                b[i].HideCards();
            }
        }
        cout << "___________________" <<endl;


    }
    void clearScreen(){
        for (int i = 0; i < 33; i++){
            cout << endl;
        }
    }

}

