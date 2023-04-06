#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class xmlFile {
protected:
    const string FILENAME;
    CMarkup xml;
    int theBiggestId;

public:
    xmlFile(string FileName) : FILENAME(FileName) {
        if (!xml.Load(FILENAME)) {
            xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
            xml.AddElem("Data");
        }
    };
    int getTheBiggestId();
    void setTheBiggestId(int newTheBiggestId);
};

#endif
