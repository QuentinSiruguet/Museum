#include "Oeuvre.h"
#include <iostream>
using namespace std;
Oeuvre::Oeuvre()
{}
Oeuvre::~Oeuvre()
{
	delete nom;
	delete code;
	delete nomFichier;
}
void Oeuvre::setNom(char* n)
{
	nom = new(char[strlen(n) + 1]);
	strcpy(nom, n);
}
void Oeuvre::setCode(char* c)
{
	code = new(char[strlen(c) + 1]);
	strcpy(code, c);
}
void Oeuvre::setNomFichier(char* f)
{
	nomFichier = new(char[strlen(f) + 1]);
	strcpy(nomFichier, f);
}
char* Oeuvre::getNom()
{
	return nom;
}
char* Oeuvre::getCode()
{
	return code;
}
char* Oeuvre::getNomFichier()
{
	return nomFichier;
}