#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class xmlFile {
protected:
    const string FILENAME;
    CMarkup xml;

public:
    xmlFile(string FileName) : FILENAME(FileName) {
        if (!xml.Load(FILENAME)) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Data");
        }
    };
};

#endif
