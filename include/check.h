//
// Created by Quentin on 06/12/2016.
//

#ifndef CONSOLEGAME_CHECK_H
#define CONSOLEGAME_CHECK_H

#include <iostream>
#include <string>
#include "tinyxml2.h"


class Check {
public :
    static bool isElementNull(tinyxml2::XMLNode *pointer, const char *s) {
        try {
            if (pointer->FirstChildElement(s) == NULL)
                throw new myError(s);
        }
        catch (myError *e) {
            std::cerr << e->XML_ELEMENT_MISSING() << std::endl;
            return true;
        }
        return false;

    };

    static bool isFileNull(const tinyxml2::XMLDocument *pointer, const char *path) {
        try {
            if (pointer->FirstChild() == NULL)
                throw new myError(path);
        }
        catch (myError *e) {
            std::cerr << e->XML_FILE_LOADING() << std::endl;
            return true;
        }
        return false;

    };

    static bool isTypeCorrect(const tinyxml2::XMLElement *pointer) {
        try {
            int test = stoi(pointer->GetText());
        }
        catch (std::invalid_argument &ia) {
            myError e(pointer->GetText());
            cerr << e.XML_TYPE_ERROR() << endl;
            return false;
        }
        catch (const std::out_of_range &oor) {
            myError e;
            cerr << e.XML_RANGE_ERROR() << endl;
            return false;
        }
        catch (exception e) {
            cerr << e.what() << endl;
            return false;
        }
        return true;

    };
/*
    try {
        int test = stoi(pointer->GetText());
    }

    catch(exception e)
    {
        cout << "Err. Not a valid entry." << endl;
        return false;
    }*/

};

#endif //CONSOLEGAME_CHECK_H
