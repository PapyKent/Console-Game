#ifndef CONSOLEGAME_STATISTIC_H
#define CONSOLEGAME_STATISTIC_H
#include <iostream>
#include <string>
using namespace std;

class Statistic
{
private:
    int statValue;
    string statName;
public:
    Statistic();
    Statistic(string, int);

    const string &getStatName();
    void setStatName(const string &statName);

    int &getStatValue();
    void setStatValue(const int &statValue);


};


#endif //CONSOLEGAME_STATISTIC_H


