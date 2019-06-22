#include <iostream>
#include <deck.h>

using namespace std;

int main(int *argc, int argv[])
{
    srand(time(0));
    Deck decks;
    vector<int> rand_card = decks.Shuffle_Cards();
    for (int i = 0; i < rand_card.size(); i++){
        int o = rand_card[i];
        decks.Order[o].printCard();
        cout << "_________" <<endl;
    }
}
