#include "../include/error.h"


const string myError::XML_FILE_LOADING() {
    return "Error : XML file not found.";
}

const string myError::XML_ELEMENT_MISSING() {
    return "Error : XML element not found. ";
}

const string myError::XML_TYPE_ERROR() {
    return "Error : XML element type is not correct";
}
