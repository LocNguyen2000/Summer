#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

struct Cards{
    string Suits;
    int Number;
    Cards(int Number_, string Suits_){
        Number = Number_;
        Suits = Suits_;
    }
    void ShowCards()
    {
        cout << Number << " of " << Suits << endl;
    }
    void HideCards()
    {
        cout << " ***** " << endl;
    }
};
class Deck{
public:
    Deck();
    ~Deck();
    vector<Cards>NewDeck;
    vector<int>Shuffle_Cards();
};

#endif // DECK_H
