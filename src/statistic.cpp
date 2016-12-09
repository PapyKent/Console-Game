#include "../include/statistic.h"


Statistic::Statistic() {
    this->statValue = 0;
}

Statistic::Statistic(string n, int v) {
    this->statValue = v;
    this->statName = n;
}

const string &Statistic::getStatName() {
    return this->statName;
}

void Statistic::setStatName(const string &statName) {
    this->statName = statName;
}

int &Statistic::getStatValue() {
    return this->statValue;
}

void Statistic::setStatValue(const int &statValue) {
    this->statValue = statValue;

}


