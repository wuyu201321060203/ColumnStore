#include <CS/XMLParse.h>
#include <CS/Initializer.h>

#include <iostream>
#include <assert.h>

XMLParse::XMLParse():idfilename("./ID.xml")
{
}

XMLParse::~XMLParse()
{
}

void XMLParse::parse()
{
    parseID();
}

void XMLParse::parseID()
{
    xmlNodePtr cur;

    doc = xmlParseFile(idfilename.c_str());
    if(nullptr == doc)
    {
        std::cerr << " fail to parse xml file  " << idfilename << std::endl;
        return;
    }

    cur = xmlDocGetRootElement(doc);
    if(nullptr == cur)
    {
        std::cerr << idfilename << " root is empty" << std::endl;
        return;
    }

    if(xmlStrcmp(cur->name, (const xmlChar*)"CONFIG"))
    {
        std::cerr << "the root is not CONFIG" << std::endl;
        return;
    }

    cur = cur->xmlChildrenNode;
    while(nullptr != cur)
    {
        if(!xmlStrcmp(cur->name, (const xmlChar*)"RAS_CONFIG"))
        {
            parse_Parameter(cur);
        }

        cur = cur->next;
    }
    xmlFreeDoc(doc);
    return;
}

void XMLParse::parse_Parameter(xmlNodePtr cur)
{
    cur = cur->xmlChildrenNode;
    xmlChar *key;
    while(nullptr != cur)
    {
        if(!xmlStrcmp(cur->name, (const xmlChar*)"MODULE_ID"))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            Initializer::_selfModuleID = atoi((char*)key);
            xmlFree(key);
        }

        if(!xmlStrcmp(cur->name, (const xmlChar*)"LISTEN_PORT"))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            std::string portstr = (char*)key;
            std::vector<std::string> portlist;
            std::string temp = "";
            for(unsigned int i = 0; i < portstr.size(); i++)
            {
                if(portstr[i] == ',')
                {
                    portlist.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += portstr[i];
                }
            }
            portlist.push_back(temp);
            assert(portlist.size() == 4);
            Initializer::_dsPort = atoi(portlist[0].c_str());
            Initializer::_cliPort = atoi(portlist[1].c_str());
            Initializer::_csPort = atoi(portlist[2].c_str());
            Initializer::_qePort = atoi(portlist[3].c_str());
            xmlFree(key);
        }

        if(!xmlStrcmp(cur->name, (const xmlChar*)"SELF_IP"))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            std::string temp = (char*)key;
            Initializer::_selfIP = temp;
            xmlFree(key);
        }

        if(!xmlStrcmp(cur->name, (const xmlChar*)"FWM_IP"))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            std::string temp = (char*)key;
            Initializer::_dcIP = temp;
            xmlFree(key);
        }

        if(!xmlStrcmp(cur->name, (const xmlChar*)"FWM_PORT"))
        {
            key = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            std::string temp = (char*)key;
            Initializer::_dcPort = atoi(temp.c_str());
            xmlFree(key);
        }
        cur = cur->next;
    }
}
