#ifndef CommunicationH
#define CommunicationH
//---------------------------------------------------------------------------
class CCommunication
{
protected:
	virtual void Initialiser() = 0;
public:
	virtual int LireMessage(void*, int) = 0;
	virtual int EnvoyerMessage(void*, int) = 0;
	virtual ~CCommunication() {};
};
#endif