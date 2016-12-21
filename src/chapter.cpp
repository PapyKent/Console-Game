#include "../include/chapter.h"

Chapter::Chapter() {

}

Chapter::Chapter(string name) {
    this->chapterName = name;
}

string Chapter::getChapterName() {
    return chapterName;
}

void Chapter::setChapterName(const string &chapterName) {
    Chapter::chapterName = chapterName;
}

void Chapter::addNode(Node n) {
    pair<string,Node> tmp (n.getNodeName(),n);
    this->nodeList.insert(tmp);

}

Node* Chapter::findNode(string key) {
    if (this->nodeList.find(key) != this->nodeList.end()){ //iterator check
        return &(this->nodeList[key]);
    }
    else
        return NULL;
}

