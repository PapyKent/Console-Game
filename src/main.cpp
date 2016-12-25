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


    bool restart = true;
    while (restart) {
        //creer et reset le joueur, son sac, ses stats
        gm.initPlayer();
        gm.getPlayer()->setPlayerName("Jo");
        gm.initCurrent();
        restart = gm.gameLoop();
    }
    cout << "Hello World!" << endl;
    return 0;
}
