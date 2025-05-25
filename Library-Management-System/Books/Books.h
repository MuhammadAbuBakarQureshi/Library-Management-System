#pragma once


#include <iostream>

#include "../Login-Registration/Keys/key.h"

#include "Doubly Books/Doubly-Books.h"

using namespace std;

const int HASH_TABLE_SIZE = 100;

class BookHashTableByBookAuthor {

public:

    Book* bookAuthorTable[HASH_TABLE_SIZE];

    BookHashTableByBookAuthor();
    ~BookHashTableByBookAuthor();

    void addBookInTable(Book* newBook);

    void searchByAuthor(string bookAuthor);

    void emptyHashTable();
};

class BookHashTableByBookTitle {

public:

    Book* bookTitleTable[HASH_TABLE_SIZE];

    BookHashTableByBookTitle();
    ~BookHashTableByBookTitle();

    void addBookInTable(Book* newBook);

    void searchByTitle(string bookTitle);

    void emptyHashTable();
};

class BookHashTableByID {

public:

    Book* bookIDTable[HASH_TABLE_SIZE];
    DoublyLinkedBooks* doublyLinkedBooks;
    BookHashTableByBookTitle* bookHashTableByBookTitle;
    BookHashTableByBookAuthor* bookHashTableByBookAuthor;

    BookHashTableByID();
    ~BookHashTableByID();

    void insertBook(string, string, string, string);

    void addBookInTable(Book*);
   
    //bool checkID(string bookID);

    void sortByTitle();

    void sortByAuthor();

    void sortByID();

    void listAllBooks();

    void listBook(Book*);

    Book* searchByID(string bookID);

    void borrowBook(string);

    void returnBook(string);

    void updateBook(string, string, string, string, string);

    bool deleteBook(string);

    void restoreBooksInTable();

    void emptyHashTable();

    void storeBooks();

    void restoreBooks();

    //void write_file();

    //void read_file();
};
