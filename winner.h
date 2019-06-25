#ifndef WINNER_H
#define WINNER_H

#include "deck.h"
int Point_Is_Straight(vector<Cards>wholeCard, int &straightP)
{
    int point = 0;
    vector<int>value;
    for (int i = 0; i < 7; i++){
        int a = wholeCard[i].Number;
        value.push_back(a);
        if (a == 1) value.push_back(14);
    }
    sort(value.begin(), value.end());
    int combo = 0;
    for (int i = value.size(); i > 0  ; i--){
        if (combo != 4)
        {
            if (value[i] - value[i-1] == 1) combo++;
            else combo = 0;
        }
        else {
            straightP = value[i];
            break;
        }
    }
    if (combo == 4)
    {
        point = 4;
    }
    return point;
}

int Point_Is_Flush(vector<Cards>wholeCard)
{
    int point = 0;
    vector<int>counter(4,0);
    vector<Cards>s;
    vector<Cards>c;
    vector<Cards>d;
    vector<Cards>h;
    for (int i = 0;i < wholeCard.size(); i++){
        string suit = wholeCard[i].Suits;
        if (suit == "Spade"){
            counter[0]++;
            s.push_back(wholeCard[i]);
        }
        else if (suit == "Club"){
            counter[1]++;
            c.push_back(wholeCard[i]);
        }
        else if (suit == "Diamond"){
            counter[2]++;
            d.push_back(wholeCard[i]);
        }
        else if (suit == "Heart"){
            counter[3]++;
            h.push_back(wholeCard[i]);
        }
    }
    int p;
    for (int i = 0; i < 4; i++){
        if (counter[i] == 5){
            p = i;
            point = 5;
            break;
        }
    }
    if (point == 5)
    {
        vector<Cards> check;
        if(p == 0) check = s;
        else if(p == 1) check = c;
        else if(p == 2) check = d;
        else if(p == 3) check = h;
        int checkStraight = Point_Is_Straight(check, p);
        if (checkStraight == 4) point = 8;
    }
    return point;
}
int
#endif // WINNER_H
