#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "chapter.h"


using namespace std;

class GameManager
{
private:
    unordered_map<string,Chapter> story;
public:
    GameManager();
};

#endif // GAMEMANAGER_H