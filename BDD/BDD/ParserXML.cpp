#include "ParserXML.h"

ParserXML::ParserXML(std::string nomFichier)
{
	this->nomFichier = nomFichier;
	this->donnees = extraireDonnees();
}

ParserXML::~ParserXML()
{
}

std::vector<Oeuvre> ParserXML::extraireDonnees()
{
	std::vector<Oeuvre> toReturn;

	rapidxml::xml_document<> doc;
	rapidxml::xml_node<>* root_node;
	// Read the xml file into a vector
	std::ifstream theFile(this->nomFichier);
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("CONFIGURATION");

	for (rapidxml::xml_node<>* salle_node = root_node->first_node("SALLE"); salle_node; salle_node = salle_node->next_sibling())
	{
		//std::cout << "Numero salle: " << salle_node->first_attribute("NUM_SALLE")->value() << std::endl;

		for (rapidxml::xml_node<>* oeuvre_node = salle_node->first_node("OEUVRE"); oeuvre_node; oeuvre_node = oeuvre_node->next_sibling())
		{
			Oeuvre data;

			data.setNom(oeuvre_node->first_attribute("NOM")->value());
			data.setCode(oeuvre_node->first_attribute("QRCODE")->value());
			data.setNomFichier(oeuvre_node->first_attribute("FICHIER")->value());

			toReturn.push_back(data);

			//std::cout << "Description : " << oeuvre_node->value() << std::endl << std::endl;
		}
		//std::cout << std::endl;
	}

	return toReturn;
}

void ParserXML::draw()
{
	for (int i = 0; i < donnees.size(); i++)
	{
		std::cout << donnees[i].getNom() << " " << donnees[i].getCode() << " " << donnees[i].getNomFichier() << std::endl;
	}
}
