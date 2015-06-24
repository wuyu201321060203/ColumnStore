#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <string>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

class XMLParse
{
public:

    explicit XMLParse();
    ~XMLParse();
    void parse();
    void parseID();

private:

    void parse_Parameter(xmlNodePtr cur);

private:

    std::string idfilename;
    xmlDocPtr doc;
};

#endif
