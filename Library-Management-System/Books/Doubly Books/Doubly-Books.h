#pragma once
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

class Book {

public:


    string bookID;
    string bookTitle;
    string bookAuthor;
    string summary;
    string genre;
    bool isAvailable;

    Book* prev;
    Book* next;
    Book* hashNext;

    // Constructor

    Book(string bookID, string bookTitle, string bookAuthor, string summary, string genre);
};


class DoublyLinkedBooks {

public:

    Book* head;
    Book* tail;
    int totalBooks;

    DoublyLinkedBooks();
    ~DoublyLinkedBooks();

    Book* insertBook(string, string, string, string, string);

};