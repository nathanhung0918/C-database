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
			cout << "請輸入檔案名稱：";
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
					cout << "欲修改同學,請選擇尋找方式";
					cmd = displayMenu(Search, className);
					//cin >> way;
					mstudent = findStudent(cmd); //學生物件
					cout << "輸入欲修改的同學資料項目";
					cmd = displayMenu(fix, className);
				//	cin >> change;//欲修改項目
					fixChoice(cmd,mstudent);
				}

				else if (cmd == 4)
				{
					int way,mstudent;
					cout << "欲修刪除同學,請選擇尋找方式";
					cmd = displayMenu(Search, className);
					//cin >> way;
					mstudent = findStudent(cmd); //學生物件
					deleteStudent(mstudent);			
				}
				else if (cmd == 5) save();
				if (cmd != 5 && cmd != 6) system("PAUSE");
				system("CLS");
			} while (cmd != 5 && cmd != 6);

		}
	} while (cmd != 2);

}
//加入學生資料
void Class::addStudent()
{
	string name,ID,phone,email;
	cout << "請輸入學生姓名";
	cin >> name;
	cout << "請輸入學生姓學號";
	cin >>	ID;
	cout << "請輸入學生電話";
	cin >> phone;
	cout << "請輸入學生信箱";
	cin >> email;
	mStudent[mNumStudent++].setStudent(name, ID,phone,email);
	cout << "新增完成" << endl;
}
//先尋找 再印出
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
			cout << "查無此學生" << endl;
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
			cout << "查無此學生" << endl;
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
			cout << "查無此學生" << endl;
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
			cout << "查無此學生" << endl;
			return -1;
		}
		return i;
		break;
	}
	return i;/////?????????
}

//給尋找方法 回傳編號
int Class::findStudent(int choice)
{
	string name,ID,phone,email; int i;
	switch(choice){
	case 1://name
		cout << "請輸入學生姓名：";
		cin >> name;
		for (i = 0; i < mNumStudent; i++)
			if (name == mStudent[i].getName()) break;
	
		if (i == mNumStudent)
		{
			cout << "查無此學生" << endl;
			return -1;
		}
		return i;
		break;
	case 2://ID
				cout << "請輸入學生學號：";
		cin >> ID;
		for (i = 0; i < mNumStudent; i++)
			if (ID == mStudent[i].getID()) break;
	
		if (i == mNumStudent)
		{
			cout << "查無此學生" << endl;
			return -1;
		}
		return i;
		break;
	case 3://phone
		cout << "請輸入學生電話：";
		cin >> phone;
		for (i = 0; i < mNumStudent; i++)
			if (phone == mStudent[i].getPhone()) break;
	
		if (i == mNumStudent)
		{
			cout << "查無此學生" << endl;
			return -1;
		}
		return i;
		break;
	case 4://email
		cout << "請輸入學生信箱：";
		cin >> email;
		for (i = 0; i < mNumStudent; i++)
			if (email == mStudent[i].getEmail()) break;
	
		if (i == mNumStudent)
		{
			cout << "查無此學生" << endl;
			return -1;
		}
		return i;
		break;
	}
	return i;/////?????????
}
//給尋找方法(CHOICE) 先尋找 再選擇更改項目
/*void Class::fixStudent(int choice)
{
	if (isEmpty()) return;
	int i = findStudent(choice);
	int item = decideWay();//選擇欲更改項目
	fixChoice(item,i);//  第i位學生
}*/

void Class::fixChoice(int change,int person)
{
	string name,ID,phone,email;
	switch(change){
	case 1:
		cout << "請輸入欲更改名字";
		cin >> name;
		mStudent[person].setName(name);
		break;
	case 2 :
		cout << "請輸入欲更改學號";
		cin >> ID;
		mStudent[person].setID(ID);
		break;
	case 3:
		cout << "請輸入欲更改電話";
		cin >> phone;
		mStudent[person].setPhone(phone);
		break;
	case 4:
		cout << "請輸入欲更改信箱";
		cin >> email;
		mStudent[person].setEmail(email);
		break;
	}
	cout << "更新完成" <<endl;
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
		cout << "資料庫內沒有任何資料" << endl;
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