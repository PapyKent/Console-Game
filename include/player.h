#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <map>
#include <string>
#include "statistic.h"
using namespace std;

class Player
{
private:
    map<string, string> playerBag;
    map<string, Statistic> playerStats;
    string playerName;
public:
    Player();
    Player(string);

    const string &getPlayerName();
    void setPlayerName(const string &choiceDestination);

    void addItemToBag(string);

    void removeItemFromBag(string);
    bool isInBag(string);

    void addStat(Statistic*);

    void removeStat(Statistic *);
    Statistic* findStat(string);
};

#endif // PLAYER_H