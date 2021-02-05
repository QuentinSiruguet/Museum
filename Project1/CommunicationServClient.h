#ifndef CommunicationServClientH
#define CommunicationServClientH
#include <Windows.h>
//---------------------------------------------------------------------------
class CCommunicationServClient
{
private:
	SOCKET* SocketService;
public:
	int LireMessage(void*, int);
	int EnvoyerMessage(void*, int);
	CCommunicationServClient(SOCKET*);
	~CCommunicationServClient();

};
#endif

