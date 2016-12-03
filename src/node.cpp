#include "../include/node.h"

Node::Node()
{

}

Node::Node(string nodeName, string nodeText){
    this->nodeName = nodeName;
    this->nodeText = nodeText;
}


string Node::getNodeName() {
    return this->nodeName;
}

void Node::setNodeName(const string &nodeName) {
    this->nodeName = nodeName;
}

string Node::getNodeText() {
    return this->nodeText;
}

void Node::setNodeText(const string &nodeText) {
    this->nodeText = nodeText;
}

vector<Choice> Node::getChoiceList() {
    return this->choiceList;
}

void Node::setChoiceList(const vector<Choice> &list) {
    this->choiceList = list;
}

void Node::addChoice(Choice choice) {
    this->choiceList.push_back(choice);

}
