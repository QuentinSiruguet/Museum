#include "Oeuvre.h"

Oeuvre::Oeuvre()
{
}

Oeuvre::~Oeuvre()
{
}

void Oeuvre::setNom(std::string nom)
{
    this->nom = nom;
}

void Oeuvre::setCode(std::string c)
{
    this->code = c;
}

void Oeuvre::setNomFichier(std::string f)
{
    this->nomFichier = f;
}

std::string Oeuvre::getNom()
{
    return this->nom;
}

std::string Oeuvre::getCode()
{
    return this->code;
}

std::string Oeuvre::getNomFichier()
{
    return this->nomFichier;
}
