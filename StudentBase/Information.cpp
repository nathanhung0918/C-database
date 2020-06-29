#include "Information.h"


Information::Information(void)
{
}


Information::~Information(void)
{
}

void Information::setName(string name)
{
	mName = name;
}
void Information::setID(string ID)
{
	mID = ID;
}
void Information::setPhone(string phone)
{
	mPhone = phone;
}

void Information::setEmail(string mail)
{
	mEmail = mail;
}

string Information::getName()
{
return mName;
}
string Information::getID()
{
	return mID;
}
string Information::getPhone()
{
	return mPhone;
}
string Information::getEmail()
{
	return mEmail; 
}
