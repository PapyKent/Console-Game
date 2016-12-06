#ifndef CONSOLEGAME_ERROR_H
#define CONSOLEGAME_ERROR_H
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class myError : public exception{
private:
    string missing;
public :
    myError();

    myError(const char *);

    const string XML_FILE_LOADING();

    const string XML_ELEMENT_MISSING();

    const string XML_TYPE_ERROR();

    const string XML_RANGE_ERROR();
};


#endif //CONSOLEGAME_ERROR_H
