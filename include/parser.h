
#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <string>
#include <vector>
#include <exception>


#include "error.h"
#include "node.h"
#include "chapter.h"
#include "check.h"
#include "gamemanager.h"

using namespace tinyxml2;

class Parser
{
private:

public:
    static void loadCharacter(GameManager& gm, const char *path);

    static void loadStory(GameManager& gm, const char *path);
};

#endif // PARSER_H
