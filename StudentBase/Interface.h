#ifndef INTERFACE_H
#define INTERFACE_H
#include "Class.h"
enum Menu {
	Main = 2,//­­¨î¿é¤J
	Operation = 6,
	Search = 4,
	fix = 4
};

int displayMenu(Menu, const char[]);
#endif