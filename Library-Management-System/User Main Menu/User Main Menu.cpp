#include <windows.h>
#include <iomanip>

#include "User-Main-Menu.h"


UserMainMenu::UserMainMenu() {

	this->bookHashTableByID = new  BookHashTableByID();
	this->bookHashTableByID->restoreBooks();
}

UserMainMenu::~UserMainMenu() {

	this->bookHashTableByID->storeBooks();
	delete this->bookHashTableByID;
}

void UserMainMenu::insertBook() {


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string bookTitle, bookAuthor, summary, genre;

	system("cls");

	SetConsoleTextAttribute(hConsole, 11); // Cyan
	cout << string(40, ' ') << "New Book Entry\n\n";
	SetConsoleTextAttribute(hConsole, 15); // Reset

	cout << "----------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 14); // Yellow
	cout << "Book Title:\n";
	SetConsoleTextAttribute(hConsole, 15); // Reset
	cout << ">> ";
	getline(cin >> ws, bookTitle);

	cout << "\n----------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Author Name:\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ">> ";
	getline(cin >> ws, bookAuthor);

	cout << "\n----------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Book Summary:\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ">> ";
	getline(cin >> ws, summary);

	cout << "\n----------------------------------------\n";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "Genre:\n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << ">> ";
	getline(cin >> ws, genre);

	cout << "\n----------------------------------------\n";

	// Insert into hash table
	bookHashTableByID->insertBook(bookTitle, bookAuthor, summary, genre);

	SetConsoleTextAttribute(hConsole, 10); // Green
	cout << "\nBook successfully inserted!\n";
	SetConsoleTextAttribute(hConsole, 15); // Reset

	cout << "\nPress Enter to return to menu...";
	cin.get();
}

void UserMainMenu::findBook() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isRunning = true;

	while (isRunning) {
		system("cls");

		SetConsoleTextAttribute(hConsole, 11); // Bright cyan
		cout << string(50, ' ') << "Search Books Menu\n\n";

		SetConsoleTextAttribute(hConsole, 15); // Reset color
		cout << "-------------------------------------------------------------\n";
		cout << " 1. Search by ID\n";
		cout << " 2. Search by Title\n";
		cout << " 3. Search by Author\n";
		cout << " 4. Exit\n";
		cout << "-------------------------------------------------------------\n";

		cout << "\nEnter your option: ";
		string option;
		cin >> option;

		cin.ignore(); // flush newline
		system("cls");

		if (option == "1") {
			string bookID;
			cout << "Enter Book ID: ";
			getline(cin >> ws, bookID);
			bookHashTableByID->searchByID(bookID);

		}
		else if (option == "2") {
			string bookTitle;
			cout << "Enter Book Title: ";
			getline(cin >> ws, bookTitle);
			bookHashTableByID->bookHashTableByBookTitle->searchByTitle(bookTitle);

		}
		else if (option == "3") {
			string bookAuthor;
			cout << "Enter Book Author: ";
			getline(cin >> ws, bookAuthor);
			bookHashTableByID->bookHashTableByBookAuthor->searchByAuthor(bookAuthor);

		}
		else if (option == "4") {
			SetConsoleTextAttribute(hConsole, 10); // Green
			cout << "\nExiting Search Menu...\n";
			SetConsoleTextAttribute(hConsole, 15); // Reset
			isRunning = false;

		}
		else {
			SetConsoleTextAttribute(hConsole, 12); // Red
			cout << "\nInvalid option. Please try again.\n";
			SetConsoleTextAttribute(hConsole, 15); // Reset
		}

		if (isRunning) {
			cout << "\nPress Enter to continue...";
			cin.get();
		}
	}
}

void UserMainMenu::run() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool isRunning = true;

	while (isRunning) {
		system("cls"); // Clear screen for fresh menu

		// Set color to bright cyan
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\n\n" << setw(50) << "User Main Menu" << "\n\n";

		// Reset color
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-------------------------------------------------------------\n";

		cout << " 1. List All Books\n";
		cout << " 2. Find Book\n";
		cout << " 3. Borrow Book\n";
		cout << " 4. Return Book\n";
		cout << " 5. Exit\n";

		cout << "-------------------------------------------------------------\n";

		cout << "\nEnter your option: ";

		string option;
		cin >> option;

		system("cls"); // Clear screen before executing option

		if (option == "1") {
			bookHashTableByID->listAllBooks();
		}
		else if (option == "2") {
			findBook();
		}
		else if (option == "3") {
			string bookID;
			cout << "Enter Book ID to borrow: ";
			cin >> bookID;
			bookHashTableByID->borrowBook(bookID);
		}
		else if (option == "4") {
			string bookID;
			cout << "Enter Book ID to return: ";
			cin >> bookID;
			bookHashTableByID->returnBook(bookID);
		}
		else if (option == "5") {
			SetConsoleTextAttribute(hConsole, 10);
			cout << "\nExiting... Have a great day!\n";
			SetConsoleTextAttribute(hConsole, 15);
			isRunning = false;
		}
		else {
			SetConsoleTextAttribute(hConsole, 12);
			cout << "\nInvalid option. Please try again.\n";
			SetConsoleTextAttribute(hConsole, 15);
		}

		cout << "\n\nPress Enter to continue...";
		cin.ignore();
		cin.get();
	}
}
