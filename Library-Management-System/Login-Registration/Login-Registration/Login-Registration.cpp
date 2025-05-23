#include <iostream>
#include <string>
#include "../Registration/Registration.h"
#include "Login-Registration.h"

using namespace std;

string to_lower(string str) {

	string lower = "";

	for (char ch : str) {

		lower += tolower(ch);
	}

	return lower;
}

bool loginRegistration() {

	cout << "\n\n\t\t\tWelcome\n" << endl;

	bool flag = false, isAdmin = false;

	while (!flag) {

		cout << "\n\n\t\t\tDo you have already account? ( y / n)\n>> ";

		string option;

		cin >> option;

		option = to_lower(option);

		if (option == "y" || option == "yes") {

			system("cls");

			cout << "\n\n\t\t\tAccount Login" << endl;

			pair<bool, bool> loginInformation = login();

			flag = loginInformation.first;
			isAdmin = loginInformation.second;
		}
		else if (option == "n" || option == "no") {
			
			system("cls");

			cout << "\n\n\t\t\tAccount Registration" << endl;

			registration();

			flag = true;
		}
		else {

			cout << "Enter correct option" << endl;
		}
	}

	if (isAdmin) return true;
	return false;
}
