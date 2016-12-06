#include "../include/error.h"

myError::myError(const char *c) {
    this->missing = c;
}

myError::myError() {

}


const string myError::XML_FILE_LOADING() {
    return "Error : XML file  " + this->missing + " not found.";
}

const string myError::XML_ELEMENT_MISSING() {
    return "Error : XML element : " + this->missing + " not found. ";
}

const string myError::XML_TYPE_ERROR() {
    return "Error : XML element ( " + this->missing + " ) type is not correct";
}


const string myError::XML_RANGE_ERROR() {
    return "Error : Out of range. ";
}

