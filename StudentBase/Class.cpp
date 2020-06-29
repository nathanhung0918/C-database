#include "Class.h"
#include "Interface.h"
#include <iostream>
#include <fstream>
using namespace std;

Class::Class(): maxStudentNum(100), mNumStudent(0)
{
	mStudent = new Student[maxStudentNum];
}


Class::~Class()
{
	
}

void Class::query()
{
	int cmd;
	do {
		cmd = displayMenu(Main, "none");
		if (cmd == 1) {
			cout << "�п�J�ɮצW�١G";
			cin >> className;
			load(className);
			system("CLS");
			do {
				cmd = displayMenu(Operation, className);
				if (cmd == 1) addStudent();
				else if (cmd == 2)
				{	
					cmd = displayMenu(Search, className);
					//int way ;
					//cin >> way;
					
					showStudent(cmd);//search by ?
			
				}
				else if (cmd == 3)
				{
					int way,mstudent,change;
					cout << "���ק�P��,�п�ܴM��覡";
					cmd = displayMenu(Search, className);
					//cin >> way;
					mstudent = findStudent(cmd); //�ǥͪ���
					cout << "��J���ק諸�P�Ǹ�ƶ���";
					cmd = displayMenu(fix, className);
				//	cin >> change;//���קﶵ��
					fixChoice(cmd,mstudent);
				}

				else if (cmd == 4)
				{
					int way,mstudent;
					cout << "���קR���P��,�п�ܴM��覡";
					cmd = displayMenu(Search, className);
					//cin >> way;
					mstudent = findStudent(cmd); //�ǥͪ���
					deleteStudent(mstudent);			
				}
				else if (cmd == 5) save();
				if (cmd != 5 && cmd != 6) system("PAUSE");
				system("CLS");
			} while (cmd != 5 && cmd != 6);

		}
	} while (cmd != 2);

}
//�[�J�ǥ͸��
void Class::addStudent()
{
	string name,ID,phone,email;
	cout << "�п�J�ǥͩm�W";
	cin >> name;
	cout << "�п�J�ǥͩm�Ǹ�";
	cin >>	ID;
	cout << "�п�J�ǥ͹q��";
	cin >> phone;
	cout << "�п�J�ǥͫH�c";
	cin >> email;
	mStudent[mNumStudent++].setStudent(name, ID,phone,email);
	cout << "�s�W����" << endl;
}
//���M�� �A�L�X
void Class::showStudent(int choice)
{
	if (isEmpty()) return;
	int i = findStudent(choice);
	if (i != -1) mStudent[i].show();
}

int Class::findStudent2(int choice) {
	string name,ID,phone,email; int i=0;
	switch(choice){
	case 1://name
		
		cin >> name;
		for (i = 0; i < mNumStudent; i++)
			if (name == mStudent[i].getName()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 2://ID
			
		cin >> ID;
		for (i = 0; i < mNumStudent; i++)
			if (ID == mStudent[i].getID()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 3://phone

		cin >> phone;
		for (i = 0; i < mNumStudent; i++)
			if (phone == mStudent[i].getPhone()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 4://email
	
		cin >> email;
		for (i = 0; i < mNumStudent; i++)
			if (email == mStudent[i].getEmail()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	}
	return i;/////?????????
}

//���M���k �^�ǽs��
int Class::findStudent(int choice)
{
	string name,ID,phone,email; int i;
	switch(choice){
	case 1://name
		cout << "�п�J�ǥͩm�W�G";
		cin >> name;
		for (i = 0; i < mNumStudent; i++)
			if (name == mStudent[i].getName()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 2://ID
				cout << "�п�J�ǥ;Ǹ��G";
		cin >> ID;
		for (i = 0; i < mNumStudent; i++)
			if (ID == mStudent[i].getID()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 3://phone
		cout << "�п�J�ǥ͹q�ܡG";
		cin >> phone;
		for (i = 0; i < mNumStudent; i++)
			if (phone == mStudent[i].getPhone()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	case 4://email
		cout << "�п�J�ǥͫH�c�G";
		cin >> email;
		for (i = 0; i < mNumStudent; i++)
			if (email == mStudent[i].getEmail()) break;
	
		if (i == mNumStudent)
		{
			cout << "�d�L���ǥ�" << endl;
			return -1;
		}
		return i;
		break;
	}
	return i;/////?????????
}
//���M���k(CHOICE) ���M�� �A��ܧ�ﶵ��
/*void Class::fixStudent(int choice)
{
	if (isEmpty()) return;
	int i = findStudent(choice);
	int item = decideWay();//��ܱ���ﶵ��
	fixChoice(item,i);//  ��i��ǥ�
}*/

void Class::fixChoice(int change,int person)
{
	string name,ID,phone,email;
	switch(change){
	case 1:
		cout << "�п�J�����W�r";
		cin >> name;
		mStudent[person].setName(name);
		break;
	case 2 :
		cout << "�п�J�����Ǹ�";
		cin >> ID;
		mStudent[person].setID(ID);
		break;
	case 3:
		cout << "�п�J�����q��";
		cin >> phone;
		mStudent[person].setPhone(phone);
		break;
	case 4:
		cout << "�п�J�����H�c";
		cin >> email;
		mStudent[person].setEmail(email);
		break;
	}
	cout << "��s����" <<endl;
}
void Class::deleteStudent(int choice)
{
	if (isEmpty()) return;
	int i = findStudent2(choice);
	mNumStudent--;
	mStudent[i] = mStudent[mNumStudent];
}
bool Class::isEmpty()
{
	if (!mNumStudent) {
		cout << "��Ʈw���S��������" << endl;
		return true;
	}
	return false;
}
void Class::save()
{
	ofstream fout(className, ios::out, ios::binary);
	fout.put(mNumStudent);
	for (int i = 0; i < mNumStudent; i++)
		mStudent[i].save(fout);
}
void Class::load(char className[])
{
	ifstream fin(className, ios::in | ios::binary);
	if (!fin) return;
	char tmp;
	fin.get(tmp); mNumStudent = tmp;
	for (int i = 0; i < mNumStudent; i++)
	    mStudent[i].load(fin);
}