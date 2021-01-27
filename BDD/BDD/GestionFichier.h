#pragma once
#include <string>

class GestionFichier
{
private:
	int taille;
	std::string buffer, nom, buffer2;
public:
	GestionFichier();
	~GestionFichier();
	void setFichier();
	std::string getBuffer();
	std::string getBuffer2(int);
	int getTaille();
	std::string getNom();
};

