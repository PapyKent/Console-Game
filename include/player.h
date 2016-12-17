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

    Player(string playerName);

    void setPlayerBag(const map<string, string> &playerBag);

    void setPlayerStats(const map<string, Statistic> &playerStats);

    string &getPlayerName();

    void setPlayerName(const string &playerName);

    void addItemToBag(string);

    bool removeItemFromBag(string);
    bool isInBag(string);

    void addStat(Statistic );

    bool removeStat(string stat);
    Statistic* findStat(string);
};

#endif // PLAYER_H