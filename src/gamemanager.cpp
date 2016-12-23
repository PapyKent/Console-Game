#include "../include/gamemanager.h"
#include "../include/check.h"

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

Player &GameManager::getPlayer() {
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

void GameManager::setCurrentNode(Node *node) {
    this->currentNode = node;
}

Node *GameManager::getCurrentNode() {
    return this->currentNode;
}


void GameManager::printNode() {
    Node *node = this->getCurrentNode();
    if (node != NULL) {
        cout << "node name : " << node->getNodeName() << endl << endl;
        cout << "node text : " << node->getNodeText() << endl << endl << endl;

        cout << "Quelle sera votre prochaine action ? " << endl << endl;

        for (int i = 0; i < node->getChoiceList().size(); i++) {
            cout << i << ": " << node->getChoiceList()[i].getChoiceText() << endl;
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
                    if (player.findStat(statName)->getStatValue() >=
                        node->getChoiceList()[i].getStatRequired().getStatValue()) {
                        cout << "stat req : " << statName << " val: "
                             << node->getChoiceList()[i].getStatRequired().getStatValue() << endl << endl;
                    } else
                        cout << "You need more " << statName << "." << endl;

                }
            }
            cout << endl;
        }
    }


}

void GameManager::initCurrent() {
    this->setCurrentChapter(this->findChapter("Introduction"));
    this->setCurrentNode(this->getCurrentChapter()->findNode("Intro1"));
}

bool GameManager::gameLoop() {

    bool game = true;
    bool continu = false;

    while (game) {
        cout << this->currentChapter->getChapterName() << endl << endl;

        printNode();
        int choice;
        string input = "";
        bool validInput = false;
        while (!validInput) {
            cout << "Quelle est votre decision ?" << endl;
            cin >> input;
            if (Check::isInt(input)) {
                choice = stoi(input);
                if (choice >= 0 && choice < getCurrentNode()->getChoiceList().size()) {
                    validInput = true;
                }
            }
        }

        string destination = getCurrentNode()->getChoiceList()[choice].getChoiceDestination();

        /*
          un robot ne peut porter atteinte à un être humain, ni, en restant passif, permettre qu'un être humain soit exposé au danger ;
          un robot doit obéir aux ordres qui lui sont donnés par un être humain, sauf si de tels ordres entrent en conflit avec la première loi ;
          un robot doit protéger son existence tant que cette protection n'entre pas en conflit avec la première ou la deuxième loi.
         */
        if (destination.compare("mort") == 0) {
            cout << " -- YOU DIE -- " << endl;
            cout << "Continuer ? 1:Oui 2:Non" << endl;
            //passer le bazar dans une fonction
        }
        //on regarde si la destination entraine un changement de chapitre
        if (this->currentChapter->findNode(destination) == NULL) {
            //passer au chap suivant et checker
        } else {
            this->currentNode = this->currentChapter->findNode(destination);
        }

    }

}





