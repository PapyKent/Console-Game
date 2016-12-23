#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "chapter.h"
#include "player.h"


using namespace std;

class GameManager
{
private:
    map<string, Chapter> story;
    Player player;
    Chapter* currentChapter;
    Node *currentNode;
public:

    GameManager();

    void addChapter(Chapter);
    Chapter* findChapter(string);

    Player& getPlayer();
    void setPlayer(Player);

    void setCurrentChapter(Chapter *  chapter);
    Chapter* getCurrentChapter();

    void setCurrentNode(Node *node);

    Node *getCurrentNode();

    void printNode();

    void initCurrent();

    bool gameLoop();
};

#endif // GAMEMANAGER_H