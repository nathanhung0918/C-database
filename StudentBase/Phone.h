#ifndef PHONE_H
#define PHONE_H
#include<string>
using namespace std;

class Phone
{
private:
	char mNumber[10];
public:
	const int maxPhoneNumberSize;
	
	Phone();
	void setPhone(string);
	string getPhone();
	~Phone(void);
	void save(ostream&);
	void load(istream&);
};

#endif