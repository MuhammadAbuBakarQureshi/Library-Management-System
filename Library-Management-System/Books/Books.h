#pragma once

#include <iostream>
#include <string>

#include "../Login-Registration/Keys/key.h"

#include "Doubly Books/Doubly-Books.h"

using namespace std;

class BookHashTableByID {

public:

    Book* bookTable[20];
    DoublyLinkedBooks* doublyLinkedBooks;

    BookHashTableByID();

    void addBook(string, string, string, string);
    
    void storeBooks();

    void restoreBooks();

    //bool checkID(string bookID);

    void searchByID(string bookID);

    //void write_file();

    //void read_file();
};

//class BookhashTableByBookTitle {
//
//public:
//
//    Book* bookTable[20];
//
//    void insertBookID();
//};
