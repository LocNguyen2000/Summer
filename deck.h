#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include<set>

using namespace std;

struct Cards{
    string Suits;
    int Number;
    bool Show = false;
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
        cout << " _ _ _ " << endl;
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
