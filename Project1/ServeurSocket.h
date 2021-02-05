#ifndef ServeurSocket_reponseH
#define ServeurSocket_reponseH
#include "Communication.h"
#include <winsock2.h>
//---------------------------------------------------------------------------
class CServeurTCP : public CCommunication
{
protected:
	void Initialiser();
private:
	SOCKET SocketEcoute;
	SOCKET* SocketService;
	char AdresseIPClient[15];
	short PortServeur;
	int lgc;
	struct sockaddr_in adr_Client;
public:
	CServeurTCP(short);
	~CServeurTCP();
	int LireMessage(void*, int);
	int EnvoyerMessage(void*, int);
	SOCKET* getSocketService();
	void AttendreConnexion();

};
#endif
