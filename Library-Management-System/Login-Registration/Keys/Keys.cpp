#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int hash_value(string key) {

	int hash = 0;
	
	for (int i = 0; i < key.length(); i++) {

		int ascii_value = int(key[i]);
		hash = (hash + (ascii_value * 23)) % 20;
	}

	return hash;
}

inline void swap(string& a, string& b) {

    string temp = a;
    a = b;
    b = temp;
}

pair<string, string> password_hashing_reg(string password) {

    // salting

    srand(time(0));

    string salt = "";

    for (int i = 0; i < 5; i++)
    {

        char character = 33 + (rand() % 93);

        salt = salt + character;
    }

    // reverse

    int i = 0, j = password.length() - 1;

    while (i < j) {

        swap(password[i], password[j]);
        i++, j--;

        if (i == j) {

            password.insert(i + 1, salt);
        }
    }

    // convert into hash

    string password_hash = "";

    for (int i = 0; i < password.length(); i++) {

        int character = password[i];

        password_hash = password_hash + to_string(character);
    }

    return make_pair(password_hash, salt);
}

string password_hashing_log(string password, string salt) {

    int i = 0, j = password.length() - 1;

    while (i < j) {

        swap(password[i], password[j]);
        i++, j--;

        if (i == j) {

            password.insert(i + 1, salt);
        }
    }

    string password_hash = "";

    for (int i = 0; i < password.length(); i++) {

        int character = password[i];

        password_hash = password_hash + to_string(character);
    }

    return password_hash;
}