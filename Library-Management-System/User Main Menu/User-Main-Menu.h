#pragma once
#include "../Books/Books.h"

class UserMainMenu {

private:

	BookHashTableByID* bookHashTableByID;

public:

	UserMainMenu();
	~UserMainMenu();

	void insertBook();

	void findBook();

	void run();
};