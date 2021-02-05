#include <string.h>
class Oeuvre
{
public:
	Oeuvre();
	~Oeuvre();
	void setNom(char* nom);
	void setCode(char* c);
	void setNomFichier(char* f);
	char* getNom();
	char* getCode();
	char* getNomFichier();
private:
	char* nom;
	char* code;
	char* nomFichier;
};
