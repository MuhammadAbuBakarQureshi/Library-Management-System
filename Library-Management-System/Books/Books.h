#pragma once

#include <iostream>

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
   
    //bool checkID(string bookID);

    void listAllBooks();

    void listBook(Book*);

    Book* searchByID(string bookID);

    void borrowBook(string);

    void returnBook(string);

    void storeBooks();

    void restoreBooks();

    //void write_file();

    //void read_file();
};