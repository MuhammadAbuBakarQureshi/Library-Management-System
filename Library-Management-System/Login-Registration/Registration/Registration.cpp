#include <iostream>
#include <string>
#include <time.h>
#include "../Keys/key.h"

using namespace std;

bool check_email_syntax(string user_email) {


    for (int i = 0; i < user_email.length(); i++) {

        char c = user_email[i];
        if (isspace(c)) {

            cout << "\n\tSpaces are not allowed" << endl;
            return false;
        }
    }

    if (user_email.find("@gmail.com") != string::npos && user_email.find("@gmail")) {

        return true;
    }
    else {

        cout << "\n\tINVALID EMAIL" << endl;

        if (user_email.find("@") != string::npos && user_email.find(".com") != string::npos) {

            cout << "\n\tOnly Google accounts are acceptable" << endl;
        }

        return false;
    }
}

string email() {

    string user_email;
        
    bool flag = false;

    while (!flag) {

        cout << "\n\n\t\t  Enter your E-mail\n\n\t\t>>";

        getline(cin >> ws, user_email);

        system("cls");

        flag = check_email_syntax(user_email);
    }

    return user_email;
}

string name() {

    cout << "Enter USER NAME : ";

    string user_name;

    getline(cin, user_name);

    for (int i = 0; i < user_name.length(); i++) {

        char c = user_name[i];

        if (isspace(c)) {

            cout << "Spaces are not allowed" << endl;
            name();
        }
    }

    return user_name;
}

string password_log(){


    string user_password;

    cout << "\n\n\t\tPassword length must be from 8 to 16 characters" << endl;

    cout << "\n\n\t\t  Enter password\n\n\t\t>>";

    getline(cin, user_password);

    system("cls");

    if (user_password.length() < 8 || user_password.length() > 16) password_log();

    return user_password;
}

pair<string, string> password() {

    string user_password = password_log();

    pair<string, string> password = password_hashing_reg(user_password);

    return make_pair(password.first, password.second);
}

void delay() {

    for (int i = 0; i < 15000000; i++) {}
}

void print_line(int n) {

    cout << "\n\n\t\t\t\t\t";

    for (int j = 0; j < n; j++) {
        delay();
        cout << "- ";
    }
}

void print_message(string message) {

    cout << "\n\n\n\n\n\n";

    print_line(25);

    cout << "\n\n\t\t\t\t\t\t\t";

    for (char c : message)
    {

        cout << c;
        delay();
    }

    cout << endl;

    system("pause");
}
