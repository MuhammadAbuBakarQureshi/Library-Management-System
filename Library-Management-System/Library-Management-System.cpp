#include <iostream>
#include "Login-Registration/Main Menu/Main_Menu.h"
#include "Books/Books.h";

using namespace std;

int main() {

	/*bool isAuthenticate = main_menu();

	if (isAuthenticate) {

		
	}*/

	Books books;
	books.addBook();
	books.getBook();

	return 0;
}
