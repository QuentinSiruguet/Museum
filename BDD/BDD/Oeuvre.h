#pragma once
#include <string>
class Oeuvre
{
private:
	std::string nom, code, nomFichier;
public:
	Oeuvre();
	~Oeuvre();
	void setNom(std::string nom);
	void setCode(std::string c);
	void setNomFichier(std::string f);
	std::string getNom();
	std::string getCode();
	std::string getNomFichier();
};

