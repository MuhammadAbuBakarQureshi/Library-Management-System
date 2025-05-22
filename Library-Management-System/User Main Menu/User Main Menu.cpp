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


	std::string bookTitle, bookAuthor, summary, genre;

	cout << "Enter book title : ";
	getline(cin >> ws, bookTitle);


	cout << "\n\nEnter author name: ";
	getline(cin >> ws, bookAuthor);

	cout << "\n\nEnter summary: ";
	getline(cin >> ws, summary);

	cout << "\n\nEnter genre: ";
	getline(cin >> ws, genre);

	bookHashTableByID->insertBook(bookTitle, bookAuthor, summary, genre);
}

void UserMainMenu::findBook() {

	std::cout << "\n\n\t\tSearch By\n\n" << std::endl;

	bool isRunning = true;

	while (isRunning) {

		std::cout << "\n\n1. Search by ID." << std::endl
			<< "2. Search by Title. \n\n" << std::endl
			<< "3. Search by Author. \n\n" << std::endl
			<< "4. Exit\n\n" << std::endl;


		string options;

		std::cin >> options;

		if (options == "1") {

			string bookID;

			cout << "\n\nEnter BookID: ";
			getline(cin >> ws, bookID);

			bookHashTableByID->searchByID(bookID);
		}
		else if (options == "2") {

			string bookTitle;

			cout << "Enter Book Title: ";
			getline(cin >> ws, bookTitle);

			bookHashTableByID->bookHashTableByBookTitle->searchByTitle(bookTitle);
		}else if (options == "3") {
		
			string bookAuthor;

			cout << "Enter Book Author: ";
			getline(cin >> ws, bookAuthor);

			bookHashTableByID->bookHashTableByBookAuthor->searchByAuthor(bookAuthor);
		}
		else if (options == "4") {

			isRunning = false;
		}
		else {

			cout << "Enter correct option" << endl;
		}
	}
}


void UserMainMenu::run() {

	std::cout << "\n\n\t\tUser Main Menu\n\n" << std::endl;

	bool isRunning = true;

	while (isRunning) {

		std::cout << "1. List All Books \n\n" << std::endl 
			<< "\n\n2. Insert book." << std::endl
			<< "3. Find Book \n\n" << std::endl
			<< "4. Borrow Book \n\n" << std::endl
			<< "5. Return Book \n\n" << std::endl
			<< "6. Exit\n\n" << std::endl;


		string options;

		std::cin >> options;

		if (options == "1") {

			this->bookHashTableByID->listAllBooks();
		}else if (options == "2") {

			this->insertBook();
		}else if(options == "3") {
		
			this->findBook();
		}
		else if (options == "4") {

			string bookID;
			cout << "Enter book ID: ";
			cin >> bookID;

			this->bookHashTableByID->borrowBook(bookID);
		}
		else if (options == "5") {

			string bookID;
			cout << "Enter book ID: ";
			cin >> bookID;
			
			this->bookHashTableByID->returnBook(bookID);
		}
		else if (options == "6") {

			isRunning = false;
		}
		else {

			cout << "Enter correct option" << endl;
		}

		/*switch (options)
		{
		case 1:

			this->addBook();
			break;

		case 2:

			isClose = true;
			break;

		default:

			cout << "enter correct one";
			break;
		}*/
	}
}