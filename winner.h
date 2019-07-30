#ifndef WINNER_H
#define WINNER_H

#include "players.h"
#include "deck.h"


namespace winner
{

int Point_Is_Straight(vector<Cards>wholeCard, int &straightP);

int Point_Is_Flush(vector<Cards>wholeCard, int &flush1, string &flushsuit);

int Point_Is_Sets(vector<Cards>wholeCard, int &point1, int &point2);

void AnouncePrize(int final_point);

}

#endif // WINNER_H
