#pragma once
#include <iostream>
#include <string>

using namespace std;

class Book {

private:

	int bookID;
	std::string bookTitle;
	std::string authorName;
	std::string summary;
	std::string genre;
	bool isAvailable;

public:

	Book(int bookID, string bookTitle, string authorName, string summary, string genre) {

		this->bookID = bookID;
		this->bookTitle = bookTitle;
		this->authorName = authorName;
		this->summary = summary;
		this->genre = genre;
		this->isAvailable = true; // True by default
	}

	void displayBook() {

		cout << "Book Title : " << bookTitle << endl
			<< "Author Name : " << authorName << endl
			<< "Summary : " << summary << endl
			<< "Genre : " << genre << endl
			<< "Book ID : " << bookID << endl
			<< "Is Available : " << isAvailable << endl;
	}
};