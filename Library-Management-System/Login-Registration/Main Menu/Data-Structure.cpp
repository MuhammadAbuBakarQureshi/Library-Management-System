#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "../Registration/Registration.h"
#include "../Keys/key.h"

using namespace std;

class Node {

public:

	string user_email;
	string password;
	string salt;
	Node* next;

	// Constructor

	Node(string user_email, string password, string salt) {

		this->user_email = user_email;
		this->password = password;
		this->salt = salt;
		next = nullptr;
	}
};

class HashTable {

public:

	Node* data_map[20];


	void add_account(string user_email, string password, string salt) {

		Node* new_account = new Node(user_email, password, salt);

		int index = hash_value(user_email);

		if (data_map[index] == nullptr) {

			data_map[index] = new_account;
			return;
		}

		for (Node* iterNode = data_map[index]; iterNode; iterNode = iterNode->next) {

			if (iterNode->next == nullptr) {

				iterNode->next = new_account;
				return;
			}
		}
	}

	bool check_email(string user_email) {

		int index = hash_value(user_email);

		if (data_map[index] == nullptr) return true;

		for (Node* iterNode = data_map[index]; iterNode; iterNode = iterNode->next) {

			if (iterNode->user_email == user_email) {

				return false;
			}
		}

		return true;
	}

    bool check_password(string user_email, string password_hash) {

        int index = hash_value(user_email);

        for (Node* iterNode = data_map[index]; iterNode; iterNode = iterNode->next) {

            if (iterNode->user_email == user_email) {

                if (iterNode->password == password_hash) return true;
            }
        }

        return false;
    }

    string password_salt(string email) {

        int index = hash_value(email);

        for (Node* iterNode = data_map[index]; iterNode; iterNode = iterNode->next) {

            if (iterNode->user_email == email) return iterNode->salt;

        }

    }

    void write_file() {

        string data = "";

        for (int i = 0; i < 20; i++) {

            Node* iterNode = data_map[i];

            if (iterNode == nullptr) {

                data += "nullptr\n";
                continue;
            }

            Node* ll_iterNode = iterNode;

            while (ll_iterNode) {

                data += ll_iterNode->user_email;
                data += ",";
                data += ll_iterNode->password;
                data += ",";
                data += ll_iterNode->salt;
                if (ll_iterNode->next == nullptr) {

                    data += ",nullptr\n";
                    break;
                }
                else {

                    data += ",next\n";
                }

                ll_iterNode = ll_iterNode->next;
            }
        }

        fstream file;

        file.open("data_base.csv", ios::out);

        if (file.is_open()) {

            file << data;
            file.close();
        }
    }

    void read_file() {

        fstream file;

        file.open("data_base.csv", ios::in);

        if (file.is_open()) {

            int i = 0;

            string data;

            while (getline(file, data)) {

                if (data == "nullptr") {

                    i++;
                    continue;
                }
                else {

                    string email, password, salt, check;

                    stringstream ss(data);

                    getline(ss, email, ',');
                    getline(ss, password, ',');
                    getline(ss, salt, ',');

                    Node* new_account = new Node(email, password, salt);

                    getline(ss, check);

                    if (data_map[i] == nullptr) {

                        data_map[i] = new_account;
                        if (check == "nullptr") i++;
                        continue;
                    }

                    for (Node* iterNode = data_map[i]; iterNode; iterNode = iterNode->next) {

                        if (iterNode->next == nullptr) {

                            iterNode->next = new_account;
                            break;
                        }
                    }

                    if (check == "nullptr") i++;


                }
            }
        }

    }
};

HashTable* hash_table = new HashTable();

int registration() {

    hash_table->read_file();

	bool flag = false;

	string user_email;

	while (!flag) {

		user_email = email();
 		flag = hash_table->check_email(user_email);
		if (!flag) cout << "There is an account already registered on this email" << endl;
	}

	// input password

	pair<string, string> user_password = password();

	hash_table->add_account(user_email, user_password.first, user_password.second);

    hash_table->write_file();

    print_message("Account Created");

	return 0;
}

bool login() {

    hash_table->read_file();

	string user_email = email();

	bool flag = hash_table->check_email(user_email);

	if (flag) {

		cout << "There is no account registered on this email\n" << endl;
		system("pause");
		return false;
	}

    flag = false;

    while (!flag) {

        string salt = hash_table->password_salt(user_email);

        string user_password = password_log();

        string password_hash = password_hashing_log(user_password, salt);

        flag = hash_table->check_password(user_email, password_hash);

        system("cls");

        if (!flag) cout << "\n\t\t Incorrect Password" << endl;
    }

    print_message("Login Successfully");

	return true;
}	