#ifndef CLASS_H
#define CLASS_H
#include "Student.h"

class Class
{
private:
	Student *mStudent;
	int mNumStudent;
	const int maxStudentNum;
	char className[512];
public:
	Class();
	~Class();
	void query();
	void addStudent();
	void showStudent(int);
	int findStudent(int);
	int findStudent2(int);
	void fixStudent(int);
	void fixChoice(int,int);
	void deleteStudent(int);
	bool isEmpty();
	void save();
	void load(char[]);
};

#endif 