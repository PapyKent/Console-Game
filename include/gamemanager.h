#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "chapter.h"


using namespace std;

class GameManager
{
private:
    map<string, Chapter> story;
public:
    GameManager();
};

#endif // GAMEMANAGER_H