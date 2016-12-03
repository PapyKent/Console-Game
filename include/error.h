#ifndef CONSOLEGAME_ERROR_H
#define CONSOLEGAME_ERROR_H
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class myError : public exception{
public :
    virtual const string XML_FILE_LOADING();
    virtual const string XML_ELEMENT_MISSING();
    virtual const string XML_TYPE_ERROR();
};


#endif //CONSOLEGAME_ERROR_H
