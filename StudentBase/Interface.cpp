#include "interface.h"
#include <iostream>
using namespace std;

int displayMenu(Menu menuType, const char dataName[]) {
	char opCode;

	cout << "�п�ܤU�C�ާ@�G" << endl;
	if (menuType == Main) {
		cout << "[1] ��J��Ʈw�ɮצW��" << endl
			 << "[2] ���}�t��" << endl;
	} else if (menuType == Operation) {
		cout << "[1] �s�W�@�W�ǥ͸��" << endl
			 << "[2] �d�߸��" << endl
			 << "[3] �����" << endl
			 << "[4] �R�����" << endl
			 << "[5] �s��" << dataName << "�ɮ�" << endl
		     << "[6] ����" << endl;
	}
	else if(menuType == Search)
	{
		cout << "[1] �m�W" << endl
			 << "[2] �Ǹ�" << endl
			 << "[3] �q��" << endl
			 << "[4] �H�c" << endl;	
	}
	else if(menuType == fix)
	{
	cout << "�п�ܭקﶵ��"
		 << "[1] �m�W" << endl
		 << "[2] �Ǹ�" << endl
		 << "[3] �q��" << endl
		 << "[4] �H�c" << endl;	
	}
	do {
		cout << " > "; 
		cin >> opCode;
	} while (!(opCode > '0' && opCode <= '0' + menuType));

	return opCode - '0';
}


