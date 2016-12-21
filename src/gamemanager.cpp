#include "../include/gamemanager.h"

GameManager::GameManager() {
    player = Player();
}

void GameManager::addChapter(Chapter chapter) {
    pair<string, Chapter> tmp(chapter.getChapterName(), chapter);
    this->story.insert(tmp);
}

Chapter *GameManager::findChapter(string key) {
    if (this->story.find(key) != this->story.end()) { //iterator check
        return &(this->story[key]);
    } else
        return NULL;
}

Player& GameManager::getPlayer() {
    this->player;
}

void GameManager::setPlayer(Player p) {
    this->player = p;

}

void GameManager::setCurrentChapter(Chapter *chapter) {
    this->currentChapter = chapter;
}

Chapter *GameManager::getCurrentChapter() {
    return this->currentChapter;
}


void GameManager::printNode(string nodeName) {
    Node *node = this->getCurrentChapter()->findNode(nodeName);
    if (node != NULL) {
        cout << "node name : " << node->getNodeName() << endl << endl;
        cout << "node text : " << node->getNodeText() << endl << endl << endl;

        for (int i = 0; i < node->getChoiceList().size(); i++) {
            cout << "choice text : " << node->getChoiceList()[i].getChoiceText() << endl;
            if (node->getChoiceList()[i].getItemRequired() != "") {
                string item = node->getChoiceList()[i].getItemRequired();
                if (player.isInBag(item))
                    cout << "item req : " << item << endl;
                else
                    cout << "You need a special item to do this. " << endl;
            }
            if (node->getChoiceList()[i].getStatRequired().getStatName() != "noStat") {
                string statName = node->getChoiceList()[i].getStatRequired().getStatName();
                if (player.findStat(statName) != NULL) {
                    if (player.findStat(statName)->getStatValue() >= node->getChoiceList()[i].getStatRequired().getStatValue()) {
                        cout << "stat req : " << statName << " val: "
                             << node->getChoiceList()[i].getStatRequired().getStatValue() << endl << endl;
                    } else
                        cout << "You need more " << statName << "." << endl;

                }
            }
            cout <<  endl;
        }
    }


}




