#include "../include/gamemanager.h"
#include "../include/check.h"

GameManager::GameManager() {
    player = new Player();
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

Player *GameManager::getPlayer() {
    return this->player;
}

void GameManager::setPlayer(Player *p) {
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
                if (player->isInBag(item))
                    cout << "item req : " << item << endl;
                else
                    cout << "You need a special item to do this. " << endl;
            }
            if (node->getChoiceList()[i].getStatRequired().getStatName() != "noStat") {
                string statName = node->getChoiceList()[i].getStatRequired().getStatName();
                if (player->findStat(statName) != NULL) {
                    if (player->findStat(statName)->getStatValue() >=
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
    this->setCurrentChapter(this->findChapter("Chapitre 1 : Introduction"));
    this->setCurrentNode(this->getCurrentChapter()->findNode("Intro1"));
}

bool GameManager::gameLoop() {

    bool game = true;
    bool continu = false;

    while (game) {
        cout << this->currentChapter->getChapterName() << endl << endl;

        printNode();
        int choice = checkUserInput(0, getCurrentNode()->getChoiceList().size());

        string destination = getCurrentNode()->getChoiceList()[choice].getChoiceDestination();

        if (destination.compare("mort") == 0) {
            cout << " -- YOU DIE -- " << endl;
            cout << "Continuer ? 1:Oui 2:Non" << endl;
            choice = checkUserInput(1, 3);
            if (choice == 1) return true;
            else return false;
        }

        if (destination.compare("fin") == 0) {
            cout << " -- THE END -- " << endl << endl;
            cout << "Recommencer ? 1:Oui 2:Non" << endl;
            choice = checkUserInput(1, 3);
            if (choice == 1) return true;
            else return false;
        }
        //on regarde si la destination entraine un changement de chapitre
        if (this->currentChapter->findNode(destination) == NULL) {
            setChapter(destination);
        } else {
            this->currentNode = this->currentChapter->findNode(destination);
        }

        cout << "------------------------------" << endl << endl;
    }


}


int GameManager::checkUserInput(int lowerValue, int upperValue) {
    int choice;
    string input = "";
    bool validInput = false;
    while (!validInput) {
        cout << "Quelle est votre decision ?" << endl;
        cin >> input;
        if (Check::isInt(input)) {
            choice = stoi(input);
            if (choice >= lowerValue && choice < upperValue) {
                validInput = true;
            }
        }
    }
    return choice;
}


void GameManager::setChapter(string destination) {

    string chapName;
    string nextChapName;
    regex integer("[[:digit:]]+");
    std::smatch sm;

    int curChapNumber;
    chapName = this->currentChapter->getChapterName();
    if (regex_search(chapName, sm, integer))
        curChapNumber = stoi(sm.str());
    else cout << "error " << endl;

    for (map<string, Chapter>::iterator it = story.begin(); it != story.end(); ++it) {
        int nextChapNumber;
        nextChapName = it->first;
        if (regex_search(nextChapName, sm, integer))
            nextChapNumber = stoi(sm.str());
        else cout << "error " << endl;

        if (nextChapNumber > curChapNumber) {
            Chapter *tmp = &(it->second);
            if (tmp->findNode(destination))
                this->setCurrentChapter(tmp);
        }
    }
}

void GameManager::initPlayer() {
    this->player = new Player();

}



