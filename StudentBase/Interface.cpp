#include "interface.h"
#include <iostream>
using namespace std;

int displayMenu(Menu menuType, const char dataName[]) {
	char opCode;

	cout << "請選擇下列操作：" << endl;
	if (menuType == Main) {
		cout << "[1] 輸入資料庫檔案名稱" << endl
			 << "[2] 離開系統" << endl;
	} else if (menuType == Operation) {
		cout << "[1] 新增一名學生資料" << endl
			 << "[2] 查詢資料" << endl
			 << "[3] 更改資料" << endl
			 << "[4] 刪除資料" << endl
			 << "[5] 存檔" << dataName << "檔案" << endl
		     << "[6] 結束" << endl;
	}
	else if(menuType == Search)
	{
		cout << "[1] 姓名" << endl
			 << "[2] 學號" << endl
			 << "[3] 電話" << endl
			 << "[4] 信箱" << endl;	
	}
	else if(menuType == fix)
	{
	cout << "請選擇修改項目"
		 << "[1] 姓名" << endl
		 << "[2] 學號" << endl
		 << "[3] 電話" << endl
		 << "[4] 信箱" << endl;	
	}
	do {
		cout << " > "; 
		cin >> opCode;
	} while (!(opCode > '0' && opCode <= '0' + menuType));

	return opCode - '0';
}


