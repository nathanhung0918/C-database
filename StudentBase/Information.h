#ifndef INFORMATION_H
#define INFORMATION_H
#include"main.h"

class Information
{
private:
	string mName;
	string mID;
	string mPhone;
	string mEmail;
	
public:
	Information();
	~Information();
	void setName(string);
	void setID(string);
	void setPhone(string);
	void setEmail(string);
	string getName();
	string getID();
	string getPhone();
	string getEmail();
	void save(ostream&);
	void load(istream&);
};
#endif

