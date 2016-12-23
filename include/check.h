//
// Created by Quentin on 06/12/2016.
//

#ifndef CONSOLEGAME_CHECK_H
#define CONSOLEGAME_CHECK_H

#include <iostream>
#include <string>
#include "tinyxml2.h"
#include "error.h"

class Check {
public :
    static bool isElementNull(tinyxml2::XMLNode *pointer, const char *s);;

    static bool isFileNull(const tinyxml2::XMLDocument *pointer, const char *path);;

    static bool isTypeCorrect(const tinyxml2::XMLElement *pointer);;

    static bool isInt(string s);
};


#endif //CONSOLEGAME_CHECK_H
