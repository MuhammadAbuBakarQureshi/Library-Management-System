#include <iostream>
#include <string>

#include "Books.h";
#include "Book.h";


using namespace std;

void Books::addBook() {

	string bookTitle, authorName, summary, genre;

	cout << "Enter book title : ";
	getline(cin >> ws, bookTitle);


	cout << "\n\nEnter author name: ";
	getline(cin >> ws, authorName);

	cout << "\n\nEnter summary: ";
	getline(cin >> ws, summary);

	cout << "\n\nEnter genre: ";
	getline(cin >> ws, genre);

	cout << "\n\n\n\n\n" << bookTitle << "\n\n" << authorName << "\n\n" << summary << "\n\n"
		<< genre << "\n\n" << bookList.size() + 1 << endl;

	Book newBook(bookList.size() + 1, bookTitle, authorName, summary, genre);

	bookList.push_back(newBook);
}

void Books::getBook() {

	int size = bookList.size();

	for (int i = 0; i < size; i++) {

		bookList.at(i).displayBook();
	}
}