#ifndef CONSOLEGAME_CHAPTER_H
#define CONSOLEGAME_CHAPTER_H
#include "node.h"
#include <unordered_map>


class Chapter {
private:
    string chapterName;
    unordered_map<string, Node> nodeList;

public:
    Chapter();
    Chapter(string name);

    string getChapterName();
    void setChapterName(const string &chapterName);

    void addNode(Node);
    Node findNode(string);


};


#endif //CONSOLEGAME_CHAPTER_H
