#include <iostream>

#include "../include/parser.h"
#include "../include/chapter.h"
#include "../include/player.h"
using namespace std;

int main(int argc, char *argv[])
{

   /* Chapter test("tmpName");

    Node node ("ceci est le titre", "ceci est le texte");
    Node node2 ("La panade", "ceci est le texte2");

    Statistic s("Agilite",5);
    Statistic s2("Agilite",5);
    Choice c ("vous voulez quoi?","La panade",s,"","Clé");
    Choice c1 ("vous voulez quoi1?","La panade",s2,"Didier","");
    Choice c2 ("vous voulez quoi2?","La panade",s,"","");

    node.addChoice(c);
    node.addChoice(c1);
    node2.addChoice(c2);

    test.addNode(node);
    test.addNode(node2);
    cout << test.findNode("La panade").getNodeText()   << endl;*/

    Player p("Jean");
    GameManager gm;
    Parser::loadStory(gm, "../../xml/story.xml");
    Parser::loadCharacter(gm, "../../xml/character.xml");

    /*map<string, Chapter> story;
    map<string, Statistic> stat;

    p.setPlayerStats(stat);
    p.addItemToBag("bibelot");
    p.addItemToBag("torche");*/

    //story.printNode("Le probleme");
    gm.findChapter("Chapitre 1 : Faux départ")->printNode("Le probleme");
    cout << "Hello World!" << endl;
    return 0;
}
