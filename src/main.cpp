#include <iostream>

#include "../include/parser.h"
#include "../include/chapter.h"
#include "../include/player.h"
using namespace std;

int main(int argc, char *argv[])
{
    GameManager gm;
    bool restart = true;
    if(!Parser::loadStory(gm, "../../xml/story.xml")) restart = false;
    if(!Parser::loadCharacter(gm, "../../xml/character.xml")) restart = false;

    while (restart) {
        gm.resetPlayer();
        //set stats
        gm.initCurrent();
        restart = gm.gameLoop();
    }
    return 0;
}
