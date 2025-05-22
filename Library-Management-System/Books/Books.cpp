#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Books.h"

using namespace std;



BookHashTableByID::BookHashTableByID()
{
    this->doublyLinkedBooks = new DoublyLinkedBooks();
    this->bookHashTableByBookTitle = new BookHashTableByBookTitle();
    this->bookHashTableByBookAuthor = new BookHashTableByBookAuthor();
}

BookHashTableByID::~BookHashTableByID()
{
    //delete[] bookIDTable;
    delete bookHashTableByBookTitle;
    delete doublyLinkedBooks;
    delete bookHashTableByBookAuthor;
}

void BookHashTableByID::insertBook(string bookTitle, string bookAuthor, string summary, string genre)
{
    Book* newBook = doublyLinkedBooks->insertBook("needed", bookTitle, bookAuthor, summary, genre);

    this->addBookInTable(newBook);
    this->bookHashTableByBookTitle->addBookInTable(newBook);
    this->bookHashTableByBookAuthor->addBookInTable(newBook);
}

void BookHashTableByID::addBookInTable(Book* newBook)
{

    //Book* newBook = doublyLinkedBooks->insertBook("needed", bookTitle, bookAuthor, summary, genre);
    
    int index = hash_value(newBook->bookID);

    if (bookIDTable[index] == nullptr) {

        bookIDTable[index] = newBook;
        return;
    }

    for (Book* iterNode = bookIDTable[index]; iterNode; iterNode = iterNode->hashNextByID) {

        if (iterNode->hashNextByID == nullptr) {

            iterNode->hashNextByID = newBook;
            return;
        }
    }
}

void BookHashTableByID::storeBooks()
{
    string data = "";    

    data += to_string(doublyLinkedBooks->totalBooks);
    data += ",\n";

    for (Book* iterNode = doublyLinkedBooks->tail; iterNode; iterNode = iterNode->prev) {

        data += iterNode->bookID;
        data += ",";
        data += iterNode->bookTitle;
        data += ",";
        data += iterNode->bookAuthor;
        data += ",";
        data += iterNode->summary;
        data += ",";
        data += iterNode->genre;
        data += ",";
        data += (iterNode->isAvailable ? "true" : "false");
        data += ",\n";
    }

    fstream file;
    
    file.open("books.txt", ios::out);
    
    if (file.is_open()) {
    
        file << data;
        file.close();
    }
}

void BookHashTableByID::restoreBooks()
{

    fstream file;
    
    file.open("books.txt", ios::in);
    
    if (file.is_open()) {
    
        string data;
    
        string firstLine;
    
        if (getline(file, firstLine)) {
    
            stringstream ss(firstLine);
    
            string totalBooks;
            getline(ss, totalBooks, ',');
    
            doublyLinkedBooks->totalBooks = stoi(totalBooks);
        }
    
    
        while (getline(file, data)) {
    
   
                string bookID, bookTitle, bookAuthor, summary, genre, isAvailable, check;
    
                stringstream ss(data);
    
                getline(ss, bookID, ',');
                getline(ss, bookTitle, ',');
                getline(ss, bookAuthor, ',');
                getline(ss, summary, ',');
                getline(ss, genre, ',');
                getline(ss, isAvailable, ',');
    
                cout << ((isAvailable == "true") ? "1" : "0") << endl;

                Book* newBook = doublyLinkedBooks->insertBook(bookID, bookTitle, bookAuthor, summary, genre);

                this->addBookInTable(newBook);
                this->bookHashTableByBookTitle->addBookInTable(newBook);
                this->bookHashTableByBookAuthor->addBookInTable(newBook);

        }
    }
}

//bool BookHashTableByID::checkID(string bookID)
//{
//
//    int index = hash_value(bookID);
//
//    if (bookTable[index] == nullptr) return true;
//
//    for (Book* iterNode = bookTable[index]; iterNode; iterNode = iterNode->next) {
//
//        if (iterNode->bookID == bookID) {
//
//            return false;
//        }
//    }
//
//    return true;
//}

void BookHashTableByID::searchByID(string bookID)
{

    int index = hash_value(bookID);

    for (Book* iterNode = bookIDTable[index]; iterNode; iterNode = iterNode->hashNextByID) {

        if (iterNode->bookID == bookID) {

            cout << iterNode->bookID << endl
                << iterNode->bookTitle << endl
                << iterNode->bookAuthor << endl
                << iterNode->summary << endl
                << iterNode->genre << endl;
            return;
        }
    }

    cout << "\n\n\n\t\tBook not Found" << endl;
}

// BOOK HASH TABLE BY BOOK TITLE


BookHashTableByBookTitle::BookHashTableByBookTitle()
{
    for (int i = 0; i < 20; ++i) {
        bookTitleTable[i] = nullptr;
    }
}

BookHashTableByBookTitle::~BookHashTableByBookTitle()
{
    //delete[] bookTitleTable;
    
}

void BookHashTableByBookTitle::addBookInTable(Book* newBook)
{

    int index = hash_value(newBook->bookTitle);

    if (bookTitleTable[index] == nullptr) {

        bookTitleTable[index] = newBook;
        return;
    }

    for (Book* iterNode = bookTitleTable[index]; iterNode; iterNode = iterNode->hashNextByTitle) {

        if (iterNode->hashNextByTitle == nullptr) {

            iterNode->hashNextByTitle = newBook;
            return;
        }
    }
}

void BookHashTableByBookTitle::searchByTitle(string bookTitle)
{

    int index = hash_value(bookTitle);

    for (Book* iterNode = bookTitleTable[index]; iterNode; iterNode = iterNode->hashNextByTitle) {

        if (iterNode->bookTitle == bookTitle) {

            cout<< iterNode->bookID << endl
                << iterNode->bookTitle << endl
                << iterNode->bookAuthor << endl
                << iterNode->summary << endl
                << iterNode->genre << endl;
            return;
        }
    }

    cout << "\n\n\n\t\tBook not Found" << endl;
}



// BY AUTHOR


BookHashTableByBookAuthor::BookHashTableByBookAuthor()
{

    for (int i = 0; i < 20; ++i) {
        bookAuthorTable[i] = nullptr;
    }
}

BookHashTableByBookAuthor::~BookHashTableByBookAuthor()
{
}

void BookHashTableByBookAuthor::addBookInTable(Book* newBook)
{


    int index = hash_value(newBook->bookAuthor);
    
    if (this->bookAuthorTable[index] == nullptr) {

        this->bookAuthorTable[index] = newBook;
        return;
    }

    for (Book* iterNode = this->bookAuthorTable[index]; iterNode; iterNode = iterNode->hashNextByAuthor) {

        if (iterNode->hashNextByAuthor == nullptr) {

            iterNode->hashNextByAuthor = newBook;
            return;
        }
    }
}

void BookHashTableByBookAuthor::searchByAuthor(string bookAuthor)
{

    int index = hash_value(bookAuthor);

    for (Book* iterNode = this->bookAuthorTable[index]; iterNode; iterNode = iterNode->hashNextByAuthor) {

        if (iterNode->bookAuthor == bookAuthor) {

            cout << iterNode->bookID << endl
                << iterNode->bookTitle << endl
                << iterNode->bookAuthor << endl
                << iterNode->summary << endl
                << iterNode->genre << endl;
            return;
        }
    }

    cout << "\n\n\n\t\tBook not Found" << endl;
}
