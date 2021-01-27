#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Oeuvre.h"
#include "rapidxml.hpp"

class ParserXML
{
private:
	std::vector<Oeuvre> donnees;
	std::string nomFichier;
public:
	ParserXML(std::string nomFichier);
	~ParserXML();
	std::vector<Oeuvre> extraireDonnees();

	void draw();
};

