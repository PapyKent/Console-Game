#include "../include/player.h"

Player::Player() {
    this->playerName = "Wagner";
}

Player::Player(string name) {
    this->playerName = name;
}


string &Player::getPlayerName() {
    return this->playerName;
}

void Player::setPlayerName(const string &playerName) {
    this->playerName = playerName;
}

void Player::addItemToBag(string item) {
    pair<string, string> tmp(item, item);
    this->playerBag.insert(tmp);
}

bool Player::removeItemFromBag(string item) {
    int i = this->playerBag.erase(item);
    return i != 0;
}

bool Player::isInBag(string item) {
    return this->playerBag.find(item) != this->playerBag.end();
}

void Player::addStat(Statistic stat) {
    pair<string, Statistic> tmp(stat.getStatName(), stat);

    this->playerStats.insert(tmp);
}

bool Player::removeStat(string stat) {
    int i = this->playerStats.erase(stat);
    return i != 0;

}

Statistic *Player::findStat(string stat) {

    if (this->playerStats.find(stat) != this->playerStats.end())
        return &this->playerStats[stat];
    else return NULL;
}

void Player::setPlayerStats(const map<string, Statistic> &playerStats) {
    this->playerStats = playerStats;
}

void Player::setPlayerBag(const map<string, string> &playerBag) {
    this->playerStats = playerStats;
}

void Player::resetStats() {
    for (map<string, Statistic>::iterator it = this->playerStats.begin(); it != this->playerStats.end(); ++it) {
        it->second.setStatValue(4);
    }
}

void Player::resetBag() {
    this->playerBag.clear();
}

map<string, Statistic> *Player::getStatsList() {
    return &playerStats;
}


