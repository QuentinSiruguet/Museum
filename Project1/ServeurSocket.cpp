#include "ServeurSocket.h"
#include <conio.h>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
CServeurTCP::CServeurTCP(short noPort)
{
	WSADATA wsaData;
	int erreur;
	// ouverture des services TCP IP de la DLL
	erreur = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (erreur != 0)
		cout << "Winsock n'a pas pu etre initialise. Erreur : " << erreur
		<< " " << WSAGetLastError() << endl;

	else
		cout << "Initialisation Winsock Ok" << endl;
	// création de la socket d'écoute du serveur.
	SocketEcoute = socket(AF_INET, SOCK_STREAM, 0);
	if (SocketEcoute == INVALID_SOCKET)
		cout << "Erreur de creation de SocketEcoute" <<
		WSAGetLastError() << endl;

	else
		cout << "Creation SocketEcoute ok" << endl;
	// Mise à jour du numéro de port d'écoute
	PortServeur = noPort;
	// Initialisation du Serveur
	Initialiser();
}
//---------------------------------------------------------------------------
CServeurTCP::~CServeurTCP()
{
	closesocket(SocketEcoute);
}
//---------------------------------------------------------------------------
void CServeurTCP::Initialiser()
{
	struct sockaddr_in adr_Serveur;
	int lg = sizeof(adr_Serveur);
	lgc = sizeof(adr_Client);
	int i;
	// description du serveur
	adr_Serveur.sin_family = AF_INET; //on travaille dans le domaine IP
	// mise en place du numéro de port du serveur
	adr_Serveur.sin_port = htons(PortServeur);
	// mise en place de l'adresse IP, n'importe laquelle
	adr_Serveur.sin_addr.s_addr = htonl(INADDR_ANY);
	// attachement de la socket au port et adresse du serveur
	i = bind(SocketEcoute, (sockaddr*)&adr_Serveur, lg);
	// mise en écoute des services réseau pour 5 demandes maximum
	i = listen(SocketEcoute, 4);
	if (i != 0)
		cout << "Impossible d'ecouter les services reseaux. Erreur " << i
		<< " : " << WSAGetLastError << endl;

}
//---------------------------------------------------------------------------
int CServeurTCP::LireMessage(void* message, int tailleMax)
{
	int nbOctetsLus;
	nbOctetsLus = recv(*SocketService, (char*)message, tailleMax, 0);
	return nbOctetsLus;
}
//---------------------------------------------------------------------------
int CServeurTCP::EnvoyerMessage(void* message, int taille)
{
	int nbOctetsEcrits;
	nbOctetsEcrits = send(*SocketService, (const char*)message, taille, 0);
	return nbOctetsEcrits;
}
//---------------------------------------------------------------------------
SOCKET* CServeurTCP::getSocketService()
{
	return SocketService;
}
//---------------------------------------------------------------------------
void CServeurTCP::AttendreConnexion()
{
	// Attente d'un client. Puis acceptation.
	int i;
	SocketService = new SOCKET;
	*SocketService = accept(SocketEcoute, (sockaddr*)&adr_Client, &lgc);
	if (*SocketService == INVALID_SOCKET)
	{

		i = WSAGetLastError();
		exit(1);
	}
}