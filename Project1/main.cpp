#include "ServeurSocket.h"
#include "GestionFichier.h"
#include "CommunicationServClient.h"
#include "ParserXML.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma comment(lib, "Ws2_32.lib")
vector <Oeuvre*> DonneesOeuvres;
vector<HANDLE> vecHandle;
vector<GestionFichier*> GestionF;
/* Fonction pour le thread de gestion des échanges avec un client */
DWORD WINAPI ThreadGestionClient(LPVOID lpParam)
{
	char buf[301];
	int nb;
	int code, codeXML;
	unsigned int i = 0;
	string tailleNom;
	CCommunicationServClient communication((SOCKET*)lpParam);
	//Communication avec le client et traitement des messages...
	//Le serveur lit le message (ici, le numéro contenu dans le QRcode)
	nb = communication.LireMessage(buf, 300);
	buf[nb] = 0;
	code = atoi(buf);
	codeXML = atoi(DonneesOeuvres[i]->getCode());
	//Compare le QRcode reçu et les QRcode du XML
	while (i < DonneesOeuvres.size() && code != codeXML)
	{
		i++;
		codeXML = atoi(DonneesOeuvres[i]->getCode());
	}
	if (code == atoi(DonneesOeuvres[i]->getCode()))
	{
		//Le serveur envoie le nom du fichier
		communication.EnvoyerMessage(GestionF[i]->GetNom(),
			strlen(GestionF[i]->GetNom()));

		//Attente de confirmation de la réception
		nb = communication.LireMessage(buf, 300);
		buf[nb] = 0;
		//Le serveur envoie la taille du fichier
		tailleNom = to_string(GestionF[i]->GetTaille()) + "\n";
		communication.EnvoyerMessage((char*)tailleNom.c_str(),
			strlen(tailleNom.c_str()));

		//Attente de confirmation de la réception
		nb = communication.LireMessage(buf, 300);
		buf[nb] = 0;
		//Le serveur envoie les données du fichier
		int n = (GestionF[i]->GetTaille() / 100) + 1;
		for (int j = 0; j < n; j++)
		{
			communication.EnvoyerMessage(GestionF[i]->GetBuffer2(j), 100);
		}
		//Attente de confirmation de la réception
		nb = communication.LireMessage(buf, 300);
		buf[nb] = 0;
	}
	ExitThread(0);
}
//---------------------------------------------------------------------------
/* Fonction pour le thread de connexion. */
DWORD WINAPI ThreadConnexion(LPVOID lpParam)
{
	DWORD ThreadIdClient; //Numéro d'identification du thread retourné à sa création
	LPVOID ThreadClientParam; //Paramètres de la fonction du thread
	CServeurTCP* LeServeur = new CServeurTCP(8888);
	while (true)
	{
		LeServeur->AttendreConnexion();
		ThreadClientParam = LeServeur->getSocketService();
		vecHandle.push_back(CreateThread(NULL, 0, ThreadGestionClient,
			&ThreadClientParam, 0, &ThreadIdClient));

	}
	delete LeServeur;
	return NULL;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	GestionFichier* GestF;
	ParserXML P((char*)".\\ConfigurationSonore.xml");
	DonneesOeuvres = P.extraireDonnees();
	cout << "Ouverture des fichiers audios à partir du fichier XML..." << endl;
	for (unsigned int i = 0; i < DonneesOeuvres.size(); i++)
	{
		cout << DonneesOeuvres[i]->getNomFichier() << "...";
		GestF = new GestionFichier;
		GestF->SetFichier(DonneesOeuvres[i]->getNomFichier());
		GestionF.push_back(GestF);
		cout << "Ok" << endl;
	}
	HANDLE hThreadConnexion; //Handle retourné par CreateHandle
	DWORD ThreadIdConnexion, ThreadConnexionParam;
	//Numéro d'identification du thread retourné à sa création
	//Paramètres de la fonction du thread
	hThreadConnexion = CreateThread(NULL, 0, ThreadConnexion,

		&ThreadConnexionParam, 0, &ThreadIdConnexion);

	cout << "appuyer sur une touche pour terminer";
	//getch();
	for (unsigned int i = 0; i < GestionF.size(); i++)
	{
		delete GestionF[i];
	}
	return 0;
}