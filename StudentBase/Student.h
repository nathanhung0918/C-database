#ifndef STUDENT_H
#define STUDENT_H
#include"Phone.h"
//#include "main.h"
#include <string>
using namespace std;

class Student
{
private:
	const int maxNameSize, maxIdSize,maxPhoneSize,maxEmailSize;
	int maxStudentNum;
	char *mName,*mID,*mEmail;
	Phone *mPhone;
public:
	Student();
	~Student(void);
	void setStudent(string,string,string,string);
	void setName(string);
	void setID(string);
	void setPhone(string);
	void setEmail(string);
	void show();
	string getName();
	string getID();
	string getPhone();
	string getEmail();
	Student& operator=(const Student&);
	void save(ostream&);
	void load(istream&);


};
#endif
