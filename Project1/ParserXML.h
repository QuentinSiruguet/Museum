#include <iostream>
#include <vector>
using namespace std;
#include "tinyxml.h"
#include "Oeuvre.h"
class ParserXML
{
public:
	ParserXML(char* nomFichier);
	~ParserXML();
	vector <Oeuvre*> extraireDonnees();
private:
	TiXmlDocument* doc;
	TiXmlElement* root;
	TiXmlElement* salle;
	TiXmlElement* oeuvre;
	TiXmlElement* donnee;
	vector <Oeuvre*> vecDonnees;
};