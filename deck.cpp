#include "deck.h"
using namespace std;

Deck::Deck()
{
    for (int i = 1; i <= 13; i++){
        string s = "Spade";
        string c = "Club"; // nhep
        string d = "Diamond";
        string h = "Heart";
        // tao bai
        Cards card_1(i, s);
        Cards card_2(i, c);
        Cards card_3(i, d);
        Cards card_4(i, h);
        // cho vao deck
        NewDeck.push_back(card_1);
        NewDeck.push_back(card_2);
        NewDeck.push_back(card_3);
        NewDeck.push_back(card_4);
    }
}
Deck::~Deck()
{}

vector<int> Deck::Shuffle_Cards()
{
    vector<int>nums;
    while (nums.size() < 52)
    {
        int randNum = rand() % 52;
        vector<int>::iterator it = find(nums.begin(), nums.end(), randNum);
        if (it == nums.end()){
            nums.push_back(randNum);
        }
    }
    return nums;
}
//*____________________________________
