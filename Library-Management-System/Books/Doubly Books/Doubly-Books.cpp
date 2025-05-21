#include "Doubly-Books.h"

Book::Book(string bookID, string bookTitle, string bookAuthor, string summary, string genre)
{

    this->bookID = bookID;
    this->bookTitle = bookTitle;
    this->bookAuthor = bookAuthor;
    this->summary = summary;
    this->genre = genre;
    this->isAvailable = true; // True by default
    this->prev = nullptr;
    this->next = nullptr;
    this->hashNext = nullptr;
}

DoublyLinkedBooks::DoublyLinkedBooks() {

    this->totalBooks = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

DoublyLinkedBooks::~DoublyLinkedBooks()
{

    delete head;
    delete tail;
}

Book* DoublyLinkedBooks::insertBook(string bookID, string bookTitle, string bookAuthor, string summary, string genre) {

    if (bookID == "needed") {

        totalBooks++;

        bookID = to_string(totalBooks);
    }


    Book* newBook = new Book(bookID, bookTitle, bookAuthor, summary, genre);

    if (this->head == nullptr) {

        this->head = newBook;
        this->tail = newBook;
    }
    else {

        this->head->prev = newBook;
        newBook->next = head;
        this->head = newBook;
    }

    return newBook;
}
