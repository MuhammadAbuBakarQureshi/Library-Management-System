#pragma once

#include <iostream>
#include <string>

#include "../Login-Registration/Keys/key.h"

#include "Doubly Books/Doubly-Books.h"

using namespace std;

class BookHashTableByBookAuthor {

public:

    Book* bookAuthorTable[20];

    BookHashTableByBookAuthor();
    ~BookHashTableByBookAuthor();

    void addBookInTable(Book* newBook);

    void searchByAuthor(string bookAuthor);
};

class BookHashTableByBookTitle {

public:

    Book* bookTitleTable[20];

    BookHashTableByBookTitle();
    ~BookHashTableByBookTitle();

    void addBookInTable(Book* newBook);

    void searchByTitle(string bookTitle);
};


class BookHashTableByID {

public:

    Book* bookIDTable[20];
    DoublyLinkedBooks* doublyLinkedBooks;
    BookHashTableByBookTitle* bookHashTableByBookTitle;
    BookHashTableByBookAuthor* bookHashTableByBookAuthor;

    BookHashTableByID();
    ~BookHashTableByID();

    void insertBook(string, string, string, string);

    void addBookInTable(Book*);
    
    void storeBooks();

    void restoreBooks();

    //bool checkID(string bookID);

    void searchByID(string bookID);

    //void write_file();

    //void read_file();
};