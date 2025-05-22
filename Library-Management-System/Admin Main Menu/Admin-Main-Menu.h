#pragma once

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <iomanip>


#include "../Books/Books.h"

class AdminMainMenu {

private:

	BookHashTableByID* bookHashTableByID;

public:

	AdminMainMenu();
	~AdminMainMenu();

	void insertBook();

	void findBook();

	void updateBook();

	void run();
};