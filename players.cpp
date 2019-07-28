#include "players.h"


using namespace winner;

Players::Players()
{
    mainPoint = 0;
    auxiliaryPoint1 = 0;
    auxiliaryPoint2 = 0;
}

Players::~Players()
{
}

void Players::TakeCards(Cards cc)
{
    hands.push_back(cc);
}

bool Players::AskPeek(int pos)
{
    char answer;
    cout <<"PLAYER " << pos+1 << " DO YOU WANT TO SEE CARDS ?  Y/N  " << endl;
    cin >> answer;
    bool result = true;
    answer == 'Y' ? result = true : result = false;
    return result;
}

int Players::EvaluateCards(vector<Cards>TableCards)
{
    int final_point = 0;
    vector<Cards>TotalHands;
    for (int i = 0; i < 2; i++){
        TotalHands.push_back(hands[i]);
    }
    for (int i = 0; i < 5; i++){
        TotalHands.push_back(TableCards[i]);
    }
    int recPoint = Point_Is_Straight(TotalHands, auxiliaryPoint1);
    final_point = recPoint;
    string flushSuit;
    recPoint = Point_Is_Flush(TotalHands, auxiliaryPoint1, flushSuit);
    if( recPoint > final_point)
        final_point = recPoint;
    recPoint = Point_Is_Sets(TotalHands,auxiliaryPoint1, auxiliaryPoint2);
    if (recPoint > final_point)
        final_point = recPoint;

    mainPoint = final_point;

    if (mainPoint == 0 || mainPoint == 5 || mainPoint == 1 || mainPoint == 2)
    {
        int mP1 = hands[0].Number;  //diem trung gian de gan bai tren tay , tranh lam thay doi bai tren tay trong th co At;
        int mP2 = hands[1].Number;
        if(mP1 == 1) mP1 = 14;
        if(mP2 == 1) mP2 = 14;
        if (mP1 < mP2)
        {
            swap(mP1, mP2);
        }
        if(mainPoint == 1)
        {
            int test1, test2; // de thay the cho AP1, Ap2
            int checkPairInBoard = Point_Is_Sets(TableCards,test1, test2);
            if (checkPairInBoard != 1)
            {
                if(mP1 == auxiliaryPoint1)
                {
                    auxiliaryPoint2 = mP2;
                }
                else auxiliaryPoint2 = mP1;
            }
            else
            {
                auxiliaryPoint1 = mP1;
                auxiliaryPoint2 = mP2;
            }
        }
        else if(mainPoint == 5)
        {
            if(hands[0].Suits == flushSuit)
            {
                auxiliaryPoint1 = hands[0].Number;
                auxiliaryPoint2 = hands[1].Number;
            }
            else if(hands[1].Suits == flushSuit)
            {
                auxiliaryPoint1 = hands[1].Number;
                auxiliaryPoint2 = hands[0].Number;
            }
            else{
            auxiliaryPoint1 = mP1;
            auxiliaryPoint2 = mP2;
            }
        }

        else if(mainPoint == 2)
        {
            int test1, test2; // de thay the cho AP1, Ap2
            int checkPairInBoard = Point_Is_Sets(TableCards,test1, test2);
            if(checkPairInBoard == 1)
            {
                if ( test1 == auxiliaryPoint1 )
                {
                    auxiliaryPoint1 = mP1;
                    swap(auxiliaryPoint1, auxiliaryPoint2);
                }
                else if(test1 == auxiliaryPoint2)
                {
                    auxiliaryPoint2 = mP1;
                }
            }
            else if(checkPairInBoard == 2)
            {
                auxiliaryPoint1 = mP1;
                auxiliaryPoint2 = mP2;
            }
        }
        else
        {
            auxiliaryPoint1 = mP1;
            auxiliaryPoint2 = mP2;
        }
    }

    //cout << "Point :    " << mainPoint << endl;
    //cout << " AP1:        " << auxiliaryPoint1 << endl;
    //cout << " AP2:        " << auxiliaryPoint2 << endl;
    return final_point;

};

void winner::DetermineWinner(vector<Players> TheP)
{
    int TheWinner;
    bool Tied = false;
    vector<int> TiedPeople;
    vector<int> MainP;
    int maxs = 0;
    for(int i = 0; i < TheP.size(); i++)
    {
        int a = TheP[i].mainPoint;
        if(a > maxs) maxs = a;
        MainP.push_back(a);
    }

    int countMainP = count(MainP.begin(), MainP.end(), maxs);
    if(countMainP > 1)
    {
        vector<int> AuP1;
        vector<int> PosPlayer;
        for(int i = 0; i < MainP.size(); i++)
          {
              if(MainP[i] == maxs)
              {
                  AuP1.push_back(TheP[i].auxiliaryPoint1);
                  PosPlayer.push_back(i);
              }
          }
        maxs = 0;
        for(int i = 0; i < AuP1.size(); i++)
        {
            int a = AuP1[i];
            if(a > maxs) maxs = a;
        }
        int countAuP1 = count(AuP1.begin(), AuP1.end(), maxs);
        if(countAuP1 > 1)
        {
            vector<int> AuP2;
            vector<int> PosPlayer2;
            for(int i = 0; i < AuP1.size(); i++)
            {
              if(AuP1[i] == maxs)
              {
                  int needPos = PosPlayer[i];
                  AuP2.push_back(TheP[needPos].auxiliaryPoint2);
                  PosPlayer2.push_back(needPos);
              }
            }
          maxs = 0;
          for(int i = 0; i < AuP2.size(); i++)
          {
            int a = AuP2[i];
            if(a > maxs) maxs = a;
          }
          int countAuP2 = count(AuP2.begin(), AuP2.end(), maxs);
          if(countAuP2 > 1)
          {
              for(int i = 0; i < AuP2.size(); i++)
              {
                  int a = AuP2[i];
                  if(a == maxs)
                  {
                     Tied = true;
                     TiedPeople.push_back(PosPlayer2[i]);
                  }
              }

          }
          else
          {
              for(int i = 0; i < AuP2.size(); i++)
              {
                  int a = AuP2[i];
                  if(a == maxs)
                  {
                      TheWinner = PosPlayer2[i];
                  }
              }
          }
        }
        else
        {
            for(int i = 0; i < AuP1.size(); i++)
            {
                int a = AuP1[i];
                if(a == maxs)
                    TheWinner = PosPlayer[i];
            }
        }
    }
    else
    {
          for(int i = 0; i < MainP.size(); i++)
          {
              if(MainP[i] == maxs)
              {
                  TheWinner = i;
              }
          }
    }


    if( Tied == true)
    {
        int numOfTied = TiedPeople.size();
        cout << numOfTied << " people are tied: " << endl;
        for(int i = 0; i < numOfTied; i++)
        {
            cout << "Player" << TiedPeople[i] + 1 << endl ;
        }
    }
    else
    {
            cout << "The Winner is : Player" << TheWinner+1 << " !!!!" << endl;
    }
}
