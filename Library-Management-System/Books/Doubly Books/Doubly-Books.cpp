#include "Doubly-Books.h"

Book::Book(string bookID, string bookTitle, string bookAuthor, string summary, string genre, bool isAvailable)
{

    this->bookID = bookID;
    this->bookTitle = bookTitle;
    this->bookAuthor = bookAuthor;
    this->summary = summary;
    this->genre = genre;
    this->isAvailable = isAvailable;

    this->prev = nullptr;
    this->next = nullptr;
    this->hashNextByID = nullptr;
    this->hashNextByTitle = nullptr;
}

DoublyLinkedBooks::DoublyLinkedBooks() {

    this->totalBooks = 0;
    this->totalBooksInserted = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

DoublyLinkedBooks::~DoublyLinkedBooks()
{

    delete head;
    delete tail;
}

Book* DoublyLinkedBooks::insertBook(string bookID, string bookTitle, string bookAuthor, string summary, string genre, bool isAvailable) {

    if (bookID == "needed") {

        totalBooksInserted++;
        totalBooks++;

        bookID = to_string(totalBooksInserted);
    }


    Book* newBook = new Book(bookID, bookTitle, bookAuthor, summary, genre, isAvailable);

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

bool DoublyLinkedBooks::deleteBook(Book* book)
{
    if (book->prev == nullptr) { // For head

        book->next->prev = nullptr;
        this->head = book->next;
        delete book;
        return true;
    }

    if (book->next == nullptr) { // For tail

        book->prev->next = nullptr;
        this->tail = book->prev;
        delete book;
        return true;
    }

    book->prev->next = book->next;
    book->next->prev = book->prev;
    delete book;
    return true;
}
