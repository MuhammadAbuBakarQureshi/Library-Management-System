#pragma once
#include <string>

using namespace std;

int hash_value(string key);

pair<string, string> password_hashing_reg(string password);

string password_log();

string password_hashing_log(string password, string salt);
