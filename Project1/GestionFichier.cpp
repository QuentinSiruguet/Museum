#include "GestionFichier.h"
GestionFichier::GestionFichier()
{}
GestionFichier::~GestionFichier()
{
	delete[]nom;
}
void GestionFichier::SetFichier(const char* nomFichier)
{
	string strNomFichier = ".\\Fichiers_Sonores\\";
	strNomFichier += nomFichier;
	nom = new char[sizeof(nomFichier) + 1];
	strcpy(nom, nomFichier);
	ifstream leFichier(strNomFichier.c_str(), ios::in | ios::binary);
	if (!leFichier.is_open())
	{
		cout << "Ouverture du fichier impossible \n";
		cerr << "Error code: " << strerror(errno);
		//getch();
		exit(2);
	}
	//Obtenir la taille du fichier
	leFichier.seekg(0, leFichier.end);
	taille = leFichier.tellg();
	leFichier.seekg(0, leFichier.beg);
	//Allocation mémoire pour le buffer
	buffer = new char[taille + 1];
	//Lecture du contenu du fichier
	leFichier.read(buffer, taille);
	buffer[taille] = '\n';
	int n = (taille / 100) + 1;
	buffer2 = new char* [n];
	char* tempbuf = new char[100];
	for (int i = 0; i < n; i++)
	{
		tempbuf = new char[100];
		memcpy(tempbuf, buffer + i * 100, 100);
		buffer2[i] = tempbuf;
	}
	leFichier.close();
}
char* GestionFichier::GetBuffer()
{
	return buffer;
}
char* GestionFichier::GetBuffer2(int n)
{
	return buffer2[n];
}

int GestionFichier::GetTaille()
{
	return taille;
}
char* GestionFichier::GetNom()
{
	return nom;
}