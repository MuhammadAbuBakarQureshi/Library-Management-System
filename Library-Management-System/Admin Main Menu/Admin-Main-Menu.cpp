#include "Admin-Main-Menu.h"

AdminMainMenu::AdminMainMenu()
{

	this->bookHashTableByID = new BookHashTableByID;
	this->bookHashTableByID->restoreBooks();
}

AdminMainMenu::~AdminMainMenu()
{
	this->bookHashTableByID->storeBooks();
	delete bookHashTableByID;
}

void AdminMainMenu::insertBook() {


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

void AdminMainMenu::findBook() {

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

void AdminMainMenu::updateBook()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	std::string bookID;
	std::cout << "\n\nEnter Book ID to update: ";
	std::getline(std::cin >> std::ws, bookID);

	Book* book = bookHashTableByID->searchByID(bookID);

	if (!book) return;

	SetConsoleTextAttribute(hConsole, 11); // Bright Cyan
	std::cout << "\n\n" << std::setw(45) << "Update Book Form\n\n";
	SetConsoleTextAttribute(hConsole, 15); // Reset color
	std::cout << "------------------------------------------------------------\n";

	std::string bookTitle, bookAuthor, summary, genre;

	std::cout << std::left << std::setw(20) << "Current Title"
		<< ": " << book->bookTitle << "\n";
	std::cout << std::left << std::setw(20) << "Enter new Title"
		<< ": ";
	std::getline(std::cin >> std::ws, bookTitle);
	if (bookTitle.empty()) bookTitle = book->bookTitle;

	std::cout << std::left << std::setw(20) << "Current Author"
		<< ": " << book->bookAuthor << "\n";
	std::cout << std::left << std::setw(20) << "Enter new Author"
		<< ": ";
	std::getline(std::cin >> std::ws, bookAuthor);
	if (bookAuthor.empty()) bookAuthor = book->bookAuthor;

	std::cout << std::left << std::setw(20) << "Current Genre"
		<< ": " << book->genre << "\n";
	std::cout << std::left << std::setw(20) << "Enter new Genre"
		<< ": ";
	std::getline(std::cin >> std::ws, genre);
	if (genre.empty()) genre = book->genre;

	std::cout << std::left << std::setw(20) << "Current Summary"
		<< ": " << book->summary << "\n";
	std::cout << std::left << std::setw(20) << "Enter new Summary"
		<< ": ";
	std::getline(std::cin >> std::ws, summary);
	if (summary.empty()) summary = book->summary;

	std::cout << "------------------------------------------------------------\n";

	// Call your update logic here
	this->bookHashTableByID->updateBook(bookID, bookTitle, bookAuthor, genre, summary);

	SetConsoleTextAttribute(hConsole, 10); // Green
	std::cout << "\nBook updated successfully!\n";
	SetConsoleTextAttribute(hConsole, 15); // Reset
}

void AdminMainMenu::deleteBook()
{
	std::string bookID;

	std::cout << "\n\n\t\t\tDelete a Book by ID\n";
	std::cout << "\t\t\t-----------------------\n";

	std::cout << "\t\t\tEnter Book ID to delete: ";
	std::cin >> bookID;

	// Assuming deleteBook returns true if successful
	bool success = bookHashTableByID->deleteBook(bookID);

	if (success) {
		std::cout << "\n\t\t\tBook with ID \"" << bookID << "\" has been successfully deleted.\n";
	}
	else {
		std::cout << "\n\t\t\tBook with ID \"" << bookID << "\" was not found.\n";
	}

}

void AdminMainMenu::sort()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isRunning = true;

	while (isRunning) {
		system("cls");

		SetConsoleTextAttribute(hConsole, 11); // Bright cyan
		cout << string(50, ' ') << "Sort Books\n\n";

		SetConsoleTextAttribute(hConsole, 15); // Reset color
		cout << "-------------------------------------------------------------\n";
		cout << " 1. Sort by ID\n";
		cout << " 2. Sort by Title\n";
		cout << " 3. Sort by Author\n";
		cout << " 4. Exit\n";
		cout << "-------------------------------------------------------------\n";

		cout << "\nEnter your option: ";
		string option;
		cin >> option;

		cin.ignore(); // flush newline
		system("cls");

		if (option == "1") {

			this->bookHashTableByID->sortByID();
		}
		else if (option == "2") {

			this->bookHashTableByID->sortByTitle();
		}
		else if (option == "3") {

			this->bookHashTableByID->sortByAuthor();
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

void AdminMainMenu::run()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	bool isRunning = true;

	while (isRunning) {
		system("cls"); // Clear screen for fresh menu

		// Set color to bright cyan
		SetConsoleTextAttribute(hConsole, 11);
		cout << "\n\n" << setw(50) << "Admin Main Menu" << "\n\n";

		// Reset color
		SetConsoleTextAttribute(hConsole, 15);
		cout << "-------------------------------------------------------------\n";

		cout << " 1. List All Books\n";
		cout << " 2. Find Book\n";
		cout << " 3. Insert Book\n";
		cout << " 4. Update Book\n";
		cout << " 5. Delete Book\n";
		cout << " 6. Sort Books\n";
		cout << " 7. Exit\n";

		cout << "-------------------------------------------------------------\n";

		cout << "\nEnter your option: ";

		string option;
		cin >> option;

		system("cls"); // Clear screen before executing option

		if (option == "1") {
			bookHashTableByID->listAllBooks();
		}
		else if (option == "2") {
			this->findBook();
		}
		else if (option == "3") {
			this->insertBook();
		}
		else if (option == "4") {
			this->updateBook();
		}
		else if (option == "5") {
			this->deleteBook();
		}else if (option == "6"){
			this->sort();
		}
		else if (option == "7") {
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
