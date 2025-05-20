#pragma once

#include <vector>

#include "Book.h";

class Books {

public:

	std::vector<Book> bookList;
	
	void addBook();

	void getBook();
};