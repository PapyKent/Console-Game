#include <iostream>

#include "../include/parser.h"
#include "../include/chapter.h"
#include "../include/player.h"
using namespace std;

int main(int argc, char *argv[])
{
    GameManager gm;
    Parser::loadStory(gm, "../../xml/story.xml");
    Parser::loadCharacter(gm, "../../xml/character.xml");

    /*map<string, Chapter> story;
    map<string, Statistic> stat;

    p.setPlayerStats(stat);
    p.addItemToBag("bibelot");
    p.addItemToBag("torche");*/

    //story.printNode("Le probleme");
    // gm.rewardEffect("patate");

    bool restart = true;
    while (restart) {
        gm.resetPlayer();
        //set stats
        gm.initCurrent();
        restart = gm.gameLoop();
    }
    cout << "Hello World!" << endl;
    return 0;
}
