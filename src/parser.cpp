#include "../include/parser.h"

void Parser::loadStory(unordered_map<string, Chapter> &story) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile("../../xml/story.xml");

    tinyxml2::XMLNode *docRoot = doc.FirstChild();
    //return null if no root element


    if (docRoot == NULL) cout << "error loading file" << endl;//error loading file
    else {
        tinyxml2::XMLElement *docChapter = docRoot->FirstChildElement("chapter");

        //parcours des chapitres
        while (docChapter != NULL) {
            Chapter chapter;

            try
            {
                if(docChapter->FirstChildElement("chapterName") == NULL)
                    throw myError;
                else
                    chapter.setChapterName(docChapter->FirstChildElement("chapterName")->GetText());
            }
            catch(myError e)
            {
                cerr << e. << endl;
            }

            // parcours des nodes
            tinyxml2::XMLElement *docNode = docChapter->FirstChildElement("node");
            while (docNode != NULL) {
                Node node;
                node.setNodeName(docNode->FirstChildElement("nodeName")->GetText());
                node.setNodeText(docNode->FirstChildElement("nodeText")->GetText());

                //parcours des choix
                tinyxml2::XMLElement *docChoice = docNode->FirstChildElement("choice");
                while (docChoice != NULL) {
                    Choice choice;
                    choice.setChoiceText(docChoice->FirstChildElement("choiceText")->GetText());
                    choice.setChoiceDestination(docChoice->FirstChildElement("destination")->GetText());

                    //check si condition
                    tinyxml2::XMLElement *docCondition = docChoice->FirstChildElement("condition");
                    if (docCondition != NULL) {
                        //check si stat
                        tinyxml2::XMLElement *docConditionItems = docCondition->FirstChildElement("stat");
                        if (docConditionItems != NULL) {
                            Statistic stat;
                            stat.setStatName(docConditionItems->FirstChildElement("statName")->GetText());
                            int statVal=0;
                            docConditionItems->FirstChildElement("value")->QueryIntText(&statVal);
                            stat.setStatValue(statVal);
                            choice.setStatRequired(&stat);
                        }
                        //check si itemRequired
                        docConditionItems = docCondition->FirstChildElement("itemRequired");
                        if (docConditionItems != NULL) {
                            choice.setItemRequired(docConditionItems->GetText());
                        }
                    }
                    tinyxml2::XMLElement *docReward = docChoice->FirstChildElement("itemReward");
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
            pair<string, Chapter> tmp(chapter.getChapterName(), chapter);
            story.insert(tmp);
            docChapter = docChapter->NextSiblingElement("chapter");
        }
        //return XML_SUCCESS;
    }

}



