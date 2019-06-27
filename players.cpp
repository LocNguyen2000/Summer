#include "players.h"
#include "winner.h"

Players::Players()
{}

Players::~Players()
{}

void Players::TakeCards(Cards cc)
{
    hands.push_back(cc);
}

bool Players::AskPeek()
{
    char answer;
    cout << "DO YOU WANT TO SEE CARDS ?  Y/N  " << endl;
    cin >> answer;
    bool result = true;
    answer == 'Y' ? result = true : result = false ;
    return result;
}

int Players::EvaluateCards(vector<Cards>TableCards)
{
    int prev_points = 0;
    int final_point = 0;
    vector<Cards>TotalHands;
    for (int i = 0; i < 2; i++){
        TotalHands.push_back(hands[i]);
    }
    for (int i = 0; i < 5; i++){
        TotalHands.push_back(TableCards[i]);
    }
    int comparedValue;
    int recPoint = Point_Is_Straight(TotalHands, comparedValue);
    final_point = recPoint;
    recPoint = Point_Is_Flush(TotalHands);
    if( recPoint > final_point)
        final_point = recPoint;
    recPoint = Point_Is_Sets(TotalHands);
    if (recPoint > final_point)
        final_point = recPoint;
        AnouncePrize(final_point);
    return final_point;

};
