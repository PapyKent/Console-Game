#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "chapter.h"
#include "player.h"
#include <regex>

using namespace std;

class GameManager
{
private:
    map<string, Chapter> story;
    Player *player;
    Chapter* currentChapter;
    Node *currentNode;
public:

    GameManager();
    ~GameManager();
    void addChapter(Chapter);
    Chapter* findChapter(string);

    Player *getPlayer();

    void setPlayer(Player *);

    void setCurrentChapter(Chapter *  chapter);
    Chapter* getCurrentChapter();

    void setCurrentNode(Node *node);

    Node *getCurrentNode();

    void printNode();

    void initCurrent();

    bool gameLoop();

    int checkUserInput(int lowerValue, int upperValue);

    void setChapter(string destination);

    void resetPlayer();

    void rewardEffect(string reward);

    void printPlayerStats();


};

#endif // GAMEMANAGER_H