#include "winner.h"

int winner::Point_Is_Straight(vector<Cards>wholeCard, int &straightP)
{
    int point = 0;
    vector<int>value;
    for (int i = 0; i < wholeCard.size(); i++){
        int a = wholeCard[i].Number;
        value.push_back(a);
        if (a == 1) value.push_back(14);
    }
    sort(value.begin(), value.end());
    int combo = 0;
    for (int i = value.size() - 1; i > 0  ; i--)
        {

            if (value[i] - value[i-1] == 1)
            {
                combo++;
                if (combo == 4)
                {
                    straightP = value[i - 1];
                    break;
                }
            }
            else if(value[i] - value[i-1] != 0) combo = 0;
    }
    if (combo == 4)
    {
        point = 4;
    }
    return point;
}

int winner::Point_Is_Flush(vector<Cards>wholeCard, int &flush1, string &flushsuit)
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
        if(p == 0)
        {
            check = s;
            flushsuit = "Spade";
        }
        else if(p == 1) {
            check = c;
            flushsuit = "Club";

        }
        else if(p == 2) {
            check = d;
            flushsuit = "Diamond";
        }
        else if(p == 3) {
            check = h;
            flushsuit = "Heart";

        }
        int checkStraight = Point_Is_Straight(check, flush1);
        if (checkStraight == 4) point = 8;
    }
    return point;
}

int winner::Point_Is_Sets(vector<Cards>wholeCard, int &point1, int &point2)
{
    int point = 0;
    vector<int> wholeValue; // mang de luu gia tri cua bai;
    for(int i = 0; i < wholeCard.size(); i++)
    {
        wholeValue.push_back(wholeCard[i].Number);
    }
    int counter;
    sort(wholeValue.begin(), wholeValue.end() );
    int currentPos = 0; // vi tri kiem tra dem;
    int numPair = 0;
    bool TOK = false, FOK = false;
    int pair1 = 0, pair2 = 0, tokVal = 0, fokVal = 0;
    while ( currentPos < wholeValue.size())
    {
        counter = count(wholeValue.begin(), wholeValue.end(), wholeValue[currentPos]);
        int midVal = wholeValue[currentPos]; //val de luu gia tri dang xet
        if(midVal == 1) midVal = 14; // truong hop la At
        currentPos+= counter;
        if (counter == 2)
        {
            numPair += 1;
            if(midVal > pair2)
            {
                pair2 = midVal;
            }
            if(pair1 < pair2)
            {
                swap(pair1, pair2);
            }
        }
        else if(counter == 3)
        {
            TOK = true;
            tokVal = midVal;
        }
        else if(counter == 4)
        {
            FOK = true;
            fokVal = midVal;
            break;
        }
    }

    if (FOK == true)
    {
        point = 7;
        point1 = fokVal;
    }
    else
    {
        if(TOK == true)
        {
            point1 = tokVal;
            if(numPair > 0)
            {
                point = 6;

                point2 = pair1;
            }
            else point = 3;
        }
        else if (numPair >= 2)
        {
            point = 2;
            point1 = pair1;
            point2 = pair2;
        }
        else if (numPair == 1)
        {
            point = 1;
            point1 = pair1;
        }
    }
    return point;
}

void winner::AnouncePrize(int final_point)
{
    switch(final_point)
    {
        case 0:
        {
            cout << " ==> High Cards" << endl;
            break;
        }
        case 1:
        {
            cout << " ==> One Pair" << endl;
            break;
        }
        case 2:
        {
            cout << " ==> Two Pairs " << endl;
            break;
        }
        case 3:
        {
            cout << " ==> Three Of A Kind " << endl;
            break;
        }
        case 4:
        {
            cout << " ==> Straight " << endl;
            break;
        }
        case 5:
            {
                cout << " ==> Flush " << endl;
                break;
            }
        case 6:
            {
                cout << " ==> Full House " << endl;
                break;
            }
        case 7:
            {
                cout << " ==> Four Of A Kind " << endl;
                break;
            }
        case 8:
            {
                cout << " ==> Straight Flush " << endl;
                break;
            }
        }
}


