
#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <string>
#include <vector>
#include <exception>

#include "tinyxml2.h"
#include "error.h"
#include "node.h"
#include "chapter.h"

//using namespace tinyxml2;

class Parser
{
private:

public:
    static void loadCharacter();
    static void loadStory(unordered_map<string,Chapter>& story);
};

#endif // PARSER_H
