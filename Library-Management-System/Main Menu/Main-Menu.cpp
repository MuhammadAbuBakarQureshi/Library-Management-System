#include <iostream>
#include <string>

#include "../Login-Registration/Login-Registration/Login-Registration.h"
#include "../User Main Menu/User-Main-Menu.h"
#include "../Admin Main Menu/Admin-Main-Menu.h"

// FOR testing

#include "../Books/Books.h"

using namespace std;

void mainMenu() {

	bool isAuthenticate = loginRegistration();

	while (true) {

		string option;
		cout << "\n\n1. Admin." << endl
			<< "2. User." << endl;
		getline(cin >> ws, option);

		if (option == "1") {

			AdminMainMenu adminMainMenu;
			adminMainMenu.run();
		}
		else if (option == "2") {

			UserMainMenu userMainMenu;
			userMainMenu.run();
		}
		else {

			cout << "\nEnter correct option" << endl;
			break;
		}
	}
}