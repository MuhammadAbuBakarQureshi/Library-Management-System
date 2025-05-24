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

// BY TITLE

Book* DoublyLinkedBooks::mergeSort(Book* start) {
    if (!start || !start->next) return start;

    Book* middle = getMiddle(start);
    Book* nextToMiddle = middle->next;
    middle->next = nullptr;
    if (nextToMiddle) nextToMiddle->prev = nullptr;

    Book* left = mergeSort(start);
    Book* right = mergeSort(nextToMiddle);

    return mergeDescending(left, right);
}

Book* DoublyLinkedBooks::mergeDescending(Book* a, Book* b) {
    if (!a) return b;
    if (!b) return a;

    Book* result = nullptr;

    if (a->bookTitle > b->bookTitle) {
        result = a;
        result->next = mergeDescending(a->next, b);
        if (result->next) result->next->prev = result;
    }
    else {
        result = b;
        result->next = mergeDescending(a, b->next);
        if (result->next) result->next->prev = result;
    }

    result->prev = nullptr;
    return result;
}

Book* DoublyLinkedBooks::getMiddle(Book* start) {
    if (!start) return start;

    Book* slow = start;
    Book* fast = start->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void DoublyLinkedBooks::sortByTitleDescending() {
    head = mergeSort(head);

    // Reset tail
    tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
}

// BY AUTHOR

Book* DoublyLinkedBooks::mergeSortByAuthor(Book* start) {
    if (!start || !start->next) return start;

    Book* middle = getMiddle(start);
    Book* nextToMiddle = middle->next;
    middle->next = nullptr;
    if (nextToMiddle) nextToMiddle->prev = nullptr;

    Book* left = mergeSortByAuthor(start);
    Book* right = mergeSortByAuthor(nextToMiddle);

    return mergeByAuthorDescending(left, right);
}

Book* DoublyLinkedBooks::mergeByAuthorDescending(Book* a, Book* b) {
    if (!a) return b;
    if (!b) return a;

    Book* result = nullptr;

    if (a->bookAuthor > b->bookAuthor) {
        result = a;
        result->next = mergeByAuthorDescending(a->next, b);
        if (result->next) result->next->prev = result;
    }
    else {
        result = b;
        result->next = mergeByAuthorDescending(a, b->next);
        if (result->next) result->next->prev = result;
    }

    result->prev = nullptr;
    return result;
}

void DoublyLinkedBooks::sortByAuthorDescending() {
    head = mergeSortByAuthor(head);

    // Reset tail after sorting
    tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
}

// BY ID

void DoublyLinkedBooks::sortByIDDescending() {
    if (!head || !head->next) return;

    head = mergeSortByID(head);

    // Fix tail pointer
    tail = head;
    while (tail && tail->next) {
        tail = tail->next;
    }
}

Book* DoublyLinkedBooks::mergeSortByID(Book* node) {
    if (!node || !node->next) return node;

    Book* middle = getMiddle(node);
    Book* nextHalf = middle->next;
    middle->next = nullptr;
    if (nextHalf) nextHalf->prev = nullptr;

    Book* left = mergeSortByID(node);
    Book* right = mergeSortByID(nextHalf);

    return mergeByIDDescending(left, right);
}

Book* DoublyLinkedBooks::mergeByIDDescending(Book* a, Book* b) {
    if (!a) return b;
    if (!b) return a;

    Book* result = nullptr;

    if (stoi(a->bookID) > stoi(b->bookID))
    {
        result = a;
        result->next = mergeByIDDescending(a->next, b);
        if (result->next) result->next->prev = result;
    }
    else {
        result = b;
        result->next = mergeByIDDescending(a, b->next);
        if (result->next) result->next->prev = result;
    }

    result->prev = nullptr;
    return result;
}
