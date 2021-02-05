#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
using namespace std;
class GestionFichier
{
public:
	GestionFichier();
	~GestionFichier();
	void SetFichier(const char* nomFichier);
	char* GetBuffer();
	char* GetBuffer2(int);
	int GetTaille();
	char* GetNom();
private:
	int taille;
	char* buffer;
	char* nom;
	char** buffer2;
};
