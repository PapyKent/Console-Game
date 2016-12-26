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

        cout << endl << endl << node->getNodeText() << endl << endl << endl;

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
        bool validStat = false, validItem = false;
        if (choice != -1) {
            if (this->currentNode->getChoiceList()[choice].getStatRequired().getStatName() != "") {
                if (this->currentNode->getChoiceList()[choice].getStatRequired().getStatValue() <= choice) {
                    validStat = true;
                } else {
                    cout << "Une de vos emotions n'est pas assez developpee." << endl << endl;
                }
            } else validStat = true;


            if (this->currentNode->getChoiceList()[choice].getItemRequired() != "") {
                if (this->getPlayer()->isInBag(this->currentNode->getChoiceList()[choice].getItemRequired())) {
                    validItem = true;
                } else {
                    cout << endl << endl << "Il vous manque un certain objet." << endl << endl;
                }
            } else validItem = true;


            if (validItem && validStat) {
                string destination = this->currentNode->getChoiceList()[choice].getChoiceDestination();

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
                    this->currentNode = this->currentChapter->findNode(destination);
                } else {
                    string reward = this->currentNode->getChoiceList()[choice].getReward();
                    if (reward != "")
                        rewardEffect(reward);
                    this->currentNode = this->currentChapter->findNode(destination);

                }
            }
        } else {
            printPlayerStats();
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
        if (input.compare("!stat") == 0)
            return -1;
        else if (Check::isInt(input)) {
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

void GameManager::resetPlayer() {
    this->player->resetBag();
    this->player->resetStats();
}

void GameManager::rewardEffect(string reward) {
    for (map<string, Statistic>::iterator it = this->getPlayer()->getStatsList()->begin();
         it != this->getPlayer()->getStatsList()->end(); ++it) {
        regex statNameRegex(it->first);
        std::smatch sm;
        if (regex_search(reward, sm, statNameRegex)) {
            string statName = sm.str();
            if (this->getPlayer()->findStat(statName) != NULL) {
                regex valueRegex("[+-]?([[:digit:]]+)");
                int value;
                std::smatch sm1;
                if (regex_search(reward, sm1, valueRegex)) {
                    value = stoi(sm1.str());
                    this->getPlayer()->findStat(statName)->setStatValue(
                            this->getPlayer()->findStat(statName)->getStatValue() + value);
                    cout << endl << endl << endl << " [!] Update Systeme : Wagner -> Augmentation du module : "
                         << statName << ". Progression : " << value << endl << endl;
                    return;
                }
            }

        }
    }

    this->getPlayer()->addItemToBag(reward);
    cout << endl << endl << "[!] Update Systeme : Wagner -> " << reward << endl << endl;

}

void GameManager::printPlayerStats() {
    for (map<string, Statistic>::iterator it = this->getPlayer()->getStatsList()->begin();
         it != this->getPlayer()->getStatsList()->end(); ++it) {
        cout << endl << it->second.getStatName() << " : " << it->second.getStatValue() << endl;
    }

}



