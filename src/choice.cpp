#include "../include/choice.h"

Choice::Choice(){

}


Choice::Choice(string choiceText,string choiceDestination,Statistic statRequired ,string itemRequired,string itemReward){
    this->choiceText = choiceText;
    this->choiceDestination = choiceDestination;
    this->statRequired = statRequired;
    this->itemRequired = itemRequired;
    this->itemReward = itemReward;
}

const string& Choice::getChoiceText(){
    return this->choiceText;
}


void Choice::setChoiceText(const string &choiceText){
    this->choiceText = choiceText;
}

const string& Choice::getChoiceDestination(){
    return this->choiceDestination;
}

void Choice::setChoiceDestination(const string &choiceDestination){
    this->choiceDestination = choiceDestination;
}

Statistic Choice::getStatRequired(){
    return this->statRequired;
}

void Choice::setStatRequired(Statistic& statRequired){
    this->statRequired = statRequired;
}


const string& Choice::getItemRequired(){
    return this->itemRequired;
}

void Choice::setItemRequired(const string &itemRequired){
    this->itemRequired = itemRequired;
}

const string& Choice::getItemReward(){
    return this->itemReward;
}

void Choice::setItemReward(const string &itemReward){
    this->itemReward = itemReward;
}

