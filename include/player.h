#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "statistic.h"
using namespace std;

class Player
{
private:
    unordered_map<string,string> playerBag;
    unordered_map<string,Statistic> playerStats;
    string playerName;
public:
    Player();
    Player(string);

    const string &getPlayerName();
    void setPlayerName(const string &choiceDestination);

    void addItemToBag(string);
    bool isInBag(string);

    void addStat(Statistic*);
    Statistic* findStat(string);
};

#endif // PLAYER_H