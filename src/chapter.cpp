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

void Chapter::printNode(string nodeName) {
    Node* node = findNode(nodeName);
    if(node != NULL){
        cout << "node name : " << node->getNodeName() << endl << endl;
        cout << "node text : " <<node->getNodeText() << endl << endl;
        vector<Choice> te = node->getChoiceList();
        std::vector<Choice>::iterator it2 = te.begin();

        //for(  std::vector<Choice>::iterator it = node->getChoiceList().begin()  ;  it != node->getChoiceList().end()  ;  it++){
        for(  int i = 0   ;  i < node->getChoiceList().size()  ;  i++){
            cout << "choice text : " << node->getChoiceList()[i].getChoiceText() << endl;
            if(node->getChoiceList()[i].getItemRequired() != "")
                cout << "item req : " << node->getChoiceList()[i].getItemRequired() << endl;
            if(node->getChoiceList()[i].getStatRequired().getStatName() != "noStat")
                cout << "stat req : " << node->getChoiceList()[i].getStatRequired().getStatName() << " val: " << node->getChoiceList()[i].getStatRequired().getStatValue() << endl<<endl;
        }
    }


}
