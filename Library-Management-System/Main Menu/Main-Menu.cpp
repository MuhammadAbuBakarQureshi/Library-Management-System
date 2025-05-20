#include <iostream>
#include <string>

#include "../Login-Registration/Login-Registration/Login-Registration.h"

using namespace std;

void mainMenu() {


	bool isAuthenticate = loginRegistration();

	if (isAuthenticate) {

		cout << "Done" << endl;
	}
}