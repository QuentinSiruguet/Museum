#include <iostream>
#include "GestionFichier.h"
#include "ParserXML.h"



void main()
{
	ParserXML parser("data.xml");
	parser.draw();
}