#include "../include/parser.h"


void Parser::loadStory(GameManager& gm, const char *path) {
    XMLDocument doc;
    doc.LoadFile(path);

    XMLNode *docRoot = NULL;
    if (!Check::isFileNull(&doc, path)) {
        docRoot = doc.FirstChild();
    }

    if (docRoot == NULL) cout << "error loading file" << endl;//error loading file
    else {
        XMLElement *docChapter;
        if (!Check::isElementNull(docRoot, "chapter")) {
            docChapter = docRoot->FirstChildElement("chapter");
        }

        //parcours des chapitres
        while (docChapter != NULL) {
            Chapter chapter;

            if (!Check::isElementNull(docChapter, "chapterName")) {
                chapter.setChapterName(docChapter->FirstChildElement("chapterName")->GetText());
            }

            // parcours des nodes
            XMLElement *docNode = NULL;
            if (!Check::isElementNull(docChapter, "node")) {
                docNode = docChapter->FirstChildElement("node");
            }
            while (docNode != NULL) {
                Node node;


                if (!Check::isElementNull(docNode, "nodeName")) {
                    node.setNodeName(docNode->FirstChildElement("nodeName")->GetText());
                }

                if (!Check::isElementNull(docNode, "nodeText")) {
                    node.setNodeText(docNode->FirstChildElement("nodeText")->GetText());
                }


                //parcours des choix

                XMLElement *docChoice = NULL;

                if (!Check::isElementNull(docNode, "choice")) {
                    docChoice = docNode->FirstChildElement("choice");
                }

                while (docChoice != NULL) {
                    Choice choice;

                    if (!Check::isElementNull(docChoice, "choiceText")) {
                        choice.setChoiceText(docChoice->FirstChildElement("choiceText")->GetText());
                    }
                    if (!Check::isElementNull(docChoice, "destination")) {
                        choice.setChoiceDestination(docChoice->FirstChildElement("destination")->GetText());
                    }

                    //check si condition
                    XMLElement *docCondition = docChoice->FirstChildElement("condition");
                    if (docCondition != NULL) {
                        //check si stat
                        XMLElement *docConditionItems = docCondition->FirstChildElement("stat");
                        if (docConditionItems != NULL) {
                            Statistic stat;
                            if (!Check::isElementNull(docConditionItems, "statName")) {
                                stat.setStatName(docConditionItems->FirstChildElement("statName")->GetText());
                            }


                            if (Check::isTypeCorrect(docConditionItems->FirstChildElement("value"))) {
                                int statVal = stoi(docConditionItems->FirstChildElement("value")->GetText());
                                //check if number
                                stat.setStatValue(statVal);
                            }

                            choice.setStatRequired(stat);
                        }
                        //check si itemRequired
                        docConditionItems;
                        docConditionItems = docCondition->FirstChildElement("itemRequired");

                        if (docConditionItems != NULL) {
                            choice.setItemRequired(docConditionItems->GetText());
                        }
                    }
                    XMLElement *docReward;
                    docReward = docChoice->FirstChildElement("itemReward");

                    //check si itemReward
                    if (docReward != NULL) {
                        choice.setItemReward(docReward->GetText());
                    }

                    node.addChoice(choice);
                    docChoice = docChoice->NextSiblingElement("choice");
                }
                chapter.addNode(node);
                docNode = docNode->NextSiblingElement("node");
            }
            gm.addChapter(chapter);
            docChapter = docChapter->NextSiblingElement("chapter");
        }
        //return XML_SUCCESS;
    }
    int tr= 0;
}

void Parser::loadCharacter(GameManager& gm, const char *path) {
    XMLDocument doc;
    doc.LoadFile(path);


    XMLNode *docRoot = NULL;
    if (!Check::isFileNull(&doc, path)) {
        docRoot = doc.FirstChild();
    }

    if (docRoot == NULL) cout << "error loading file" << endl;//error loading file
    else {
        XMLElement *docStats;
        if (!Check::isElementNull(docRoot, "stat")) {
            docStats = docRoot->FirstChildElement("stat");
        }

        //parcours des stats
        while (docStats != NULL) {
            Statistic stat;
            stat.setStatValue(0);
            stat.setStatName(docStats->GetText());
            gm.getPlayer()->addStat(stat);
            docStats = docStats->NextSiblingElement("stat");
        }
        gm.getPlayer()->setPlayerName("Carl");

        //return XML_SUCCESS;
    }
}



