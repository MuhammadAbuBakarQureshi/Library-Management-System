#include <iostream>
#include <string>

#include "../Login-Registration/Login-Registration/Login-Registration.h"
#include "../User Main Menu/User-Main-Menu.h"

// FOR testing

#include "../Books/Books.h"

using namespace std;

void mainMenu() {

	//BookHashTableByID* bookHashTableByID = new BookHashTableByID();

	//bookHashTableByID->restoreBooks();

	//string bookID, bookTitle, bookAuthor, summary, genre;

	//bookTitle = "Atomic habits";
	//bookAuthor = "Bakar";
	//summary = "This books helps you to replace your bad habits with good ones";
	//genre = "Self-Improvement";

	//
	//bookHashTableByID->insertBook(bookTitle, bookAuthor, summary, genre);

	//bookTitle = "Money power";
	//bookAuthor = "Abdullah";
	//summary = "It explains power of money";
	//genre = "Power";

	//bookHashTableByID->insertBook(bookTitle, bookAuthor, summary, genre);

	//bookHashTableByID->storeBooks();


	UserMainMenu userMainMenu;
	
	userMainMenu.run();



	// return true if successful

	//bool isAuthenticate = loginRegistration();

	//BookHashTableByID* bookHashTableByID = new BookHashTableByID();

	//bookHashTableByID->read_file();

	//string bookID, bookTitle, bookAuthor, summary, genre;

	//bookTitle = "Atomic habits";
	//bookAuthor = "Bakar";
	//summary = "This books helps you to replace your bad habits with good ones";
	//genre = "Self-Improvement";

	//bookHashTableByID->addBook(bookTitle, bookAuthor, summary, genre);

	//bookHashTableByID->write_file();
	
}