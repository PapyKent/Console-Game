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
public:
    GameManager();

    void addChapter(Chapter);
    Chapter* findChapter(string);

    Player& getPlayer();
    void setPlayer(Player);
};

#endif // GAMEMANAGER_H