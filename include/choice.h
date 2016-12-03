#ifndef CONSOLEGAME_CHOICE_H
#define CONSOLEGAME_CHOICE_H
#include "../include/statistic.h"

class Choice {
private:
    string choiceText;
    string choiceDestination;
    Statistic* statRequired;
    string itemRequired;
    string itemReward;
public:
    Choice();
    Choice(string,string,Statistic*,string,string);

    const string &getChoiceText();
    void setChoiceText(const string &choiceText);

    const string &getChoiceDestination();
    void setChoiceDestination(const string &choiceDestination);

    Statistic* getStatRequired();
    void setStatRequired(Statistic* statRequired);

    const string &getItemRequired();
    void setItemRequired(const string &itemRequired);

    const string &getItemReward();
    void setItemReward(const string &itemReward);

};


#endif //CONSOLEGAME_CHOICE_H
