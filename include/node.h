#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include "../include/choice.h"

using namespace std;

class Node
{
private:
    string nodeName;
    string nodeText;
    vector<Choice> choiceList;
public:
    Node();
    Node(string nodeName, string nodeText);


    string getNodeName();
    void setNodeName(const string &nodeName);

    string getNodeText();
    void setNodeText(const string &nodeText);

    vector<Choice> getChoiceList();
    void setChoiceList(const vector<Choice> &list);

    void addChoice (Choice choice);
};

#endif // NODE_H
