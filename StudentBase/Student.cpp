#include"Student.h"
//#include"main.h"
#include <iostream>



Student::Student():maxNameSize(10), maxIdSize(10),maxPhoneSize(10),maxEmailSize(10),maxStudentNum(100)
{
	mName = new char[10];
	mID = new char[10];
	//mPhone = new char[10];
	mEmail = new char[10];
	mPhone = new Phone[2];
	//mPhone = new Phone();
}


Student::~Student(void)
{
	delete [] mName;
	delete [] mID;
//	delete [] mPhone;
	delete [] mEmail;
}

void Student::setStudent(string name,string ID,string phone,string email )
{
	strcpy(mName, name.c_str());
	strcpy(mID, ID.c_str());
	//strcpy(mPhone, phone.c_str());
	strcpy(mEmail, email.c_str());
	setPhone(phone);
}
void Student::setName(string name)
{
	strcpy(mName, name.c_str());
}
void Student::setID(string ID)
{
	strcpy(mID, ID.c_str());
}
void Student::setPhone(string phone)
{
	mPhone->setPhone(phone);
}

void Student::setEmail(string email)
{
	strcpy(mEmail, email.c_str());
}

string Student::getName()
{
return mName;
}
string Student::getID()
{
	return mID;
}
string Student::getPhone()
{
	 return mPhone->getPhone();
}
string Student::getEmail()
{
	return mEmail; 
}

void Student::show() {
	cout << "名字：" << mName << endl
		 << "學號：" << mID << endl
		 << "電話：" << mPhone->getPhone() << endl
		 << "信箱：" << mEmail << endl;	
}

Student& Student::operator=(const Student &s) {
	//if(&s == this)return *this;
	mName = s.mName;
	mID = s.mID;
	mPhone = s.mPhone;
	mEmail = s.mEmail;
	return *this;
}
void Student::save(ostream &os) {
	os.write(mName, maxNameSize);
	os.write(mID, maxIdSize);
	//os.write(mPhone, maxPhoneSize);
	mPhone->save(os);
	os.write(mEmail, maxEmailSize);


}

void Student::load(istream &fin) {
	fin.read(mName, maxNameSize);
	fin.read(mID, maxIdSize);
	//fin.read(mPhone, maxPhoneSize);
	mPhone->load(fin);
	fin.read(mEmail, maxEmailSize);


}