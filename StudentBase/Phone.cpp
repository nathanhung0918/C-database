#include "Phone.h"
#include<string>
#include <iostream>
using namespace std;

Phone::Phone():maxPhoneNumberSize(10)
{

}

void Phone::setPhone(string number)
{
	strcpy(mNumber,number.c_str());
}
string Phone::getPhone()
{
	return mNumber;
}

Phone::~Phone(void)
{

}

void Phone::save(ostream &os)
{
	os.write(mNumber,maxPhoneNumberSize);

}

void Phone::load(istream &fin)
{
	fin.read(mNumber, maxPhoneNumberSize);
}
