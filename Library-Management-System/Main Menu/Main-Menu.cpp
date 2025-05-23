#include <iostream>
#include <string>

#include "../Login-Registration/Login-Registration/Login-Registration.h"
#include "../User Main Menu/User-Main-Menu.h"
#include "../Admin Main Menu/Admin-Main-Menu.h"

using namespace std;

void mainMenu() {

	bool isAdmin = loginRegistration();

	if (isAdmin) {

		AdminMainMenu adminMainMenu;
		adminMainMenu.run();
	}
	else {

		UserMainMenu userMainMenu;
		userMainMenu.run();
	}
}
