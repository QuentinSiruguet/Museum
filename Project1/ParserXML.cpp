#include "ParserXML.h"
ParserXML::ParserXML(char* nomFichier)
{
	doc = new TiXmlDocument(nomFichier);
	if (!doc->LoadFile()) // ouverture du fichier XML
	{
		cout << "load file error" << endl;
		cout << "error #" << doc->ErrorId() << " : " << doc->ErrorDesc() << endl;
	}
}
ParserXML::~ParserXML()
{
	delete doc;
	for (unsigned int i = 0; i < vecDonnees.size(); i++)
	{
		delete vecDonnees[i];
	}
}
vector <Oeuvre*> ParserXML::extraireDonnees()
{
	Oeuvre* o;
	root = doc->RootElement();
	salle = root->FirstChildElement();
	while (salle)
	{
		oeuvre = salle->FirstChildElement();
		while (oeuvre)
		{
			donnee = oeuvre->FirstChildElement();
			if (donnee)
			{
				o = new(Oeuvre);
				o->setNom((char*)donnee->FirstChild()->Value());
				donnee = donnee->NextSiblingElement();
				o->setCode((char*)donnee->FirstChild()->Value());
				donnee = donnee->NextSiblingElement();
				o->setNomFichier((char*)donnee->FirstChild()->Value());
				donnee = donnee->NextSiblingElement();
				vecDonnees.push_back(o);
			}
			oeuvre = oeuvre->NextSiblingElement();
		}
		salle = salle->NextSiblingElement();
	}
	return vecDonnees;
}