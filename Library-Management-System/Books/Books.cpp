#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

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
    Book* newBook = doublyLinkedBooks->insertBook("needed", bookTitle, bookAuthor, summary, genre, "1");

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

void BookHashTableByID::listAllBooks()
{

        const string HEADER_COLOR = "\033[1;36m";  // Cyan
        const string RESET_COLOR = "\033[0m";
        const string LINE_COLOR = "\033[1;37m";    // Light Gray

        const int idWidth = 4;
        const int titleWidth = 20;
        const int authorWidth = 15;
        const int summaryWidth = 40;
        const int genreWidth = 15;
        const int availWidth = 10;

        // Print centered heading
        string heading = "BOOK LISTING";
        int consoleWidth = 100;
        int padding = (consoleWidth - heading.length()) / 2;
        cout << "\n\n" << string(padding, ' ') << HEADER_COLOR << heading << RESET_COLOR << "\n\n";

        // Print top border
        cout << LINE_COLOR
            << "+" << string(idWidth + 2, '-')
            << "+" << string(titleWidth + 2, '-')
            << "+" << string(authorWidth + 2, '-')
            << "+" << string(summaryWidth + 2, '-')
            << "+" << string(genreWidth + 2, '-')
            << "+" << string(availWidth + 2, '-')
            << "+" << RESET_COLOR << endl;

        // Print column headers
        cout << LINE_COLOR
            << "| " << left << setw(idWidth) << "ID"
            << " | " << setw(titleWidth) << "Title"
            << " | " << setw(authorWidth) << "Author"
            << " | " << setw(summaryWidth) << "Summary"
            << " | " << setw(genreWidth) << "Genre"
            << " | " << setw(availWidth) << "Available"
            << " |" << RESET_COLOR << endl;

        // Print middle border
        cout << LINE_COLOR
            << "+" << string(idWidth + 2, '-')
            << "+" << string(titleWidth + 2, '-')
            << "+" << string(authorWidth + 2, '-')
            << "+" << string(summaryWidth + 2, '-')
            << "+" << string(genreWidth + 2, '-')
            << "+" << string(availWidth + 2, '-')
            << "+" << RESET_COLOR << endl;

        // Print all books
        for (Book* iterNode = doublyLinkedBooks->tail; iterNode; iterNode = iterNode->prev) {
            auto truncate = [](string str, int width) {
                return (str.length() > width) ? str.substr(0, width - 3) + "..." : str;
                };

            string bookID = iterNode->bookID;
            string title = truncate(iterNode->bookTitle, titleWidth);
            string author = truncate(iterNode->bookAuthor, authorWidth);
            string summary = truncate(iterNode->summary, summaryWidth);
            string genre = truncate(iterNode->genre, genreWidth);
            string isAvailable = iterNode->isAvailable ? "Yes" : "No";

            cout << "| " << left << setw(idWidth) << bookID
                << " | " << setw(titleWidth) << title
                << " | " << setw(authorWidth) << author
                << " | " << setw(summaryWidth) << summary
                << " | " << setw(genreWidth) << genre
                << " | " << setw(availWidth) << isAvailable
                << " |" << endl;
        }


        // Print bottom border
        cout << LINE_COLOR
            << "+" << string(idWidth + 2, '-')
            << "+" << string(titleWidth + 2, '-')
            << "+" << string(authorWidth + 2, '-')
            << "+" << string(summaryWidth + 2, '-')
            << "+" << string(genreWidth + 2, '-')
            << "+" << string(availWidth + 2, '-')
            << "+" << RESET_COLOR << endl;
}

void BookHashTableByID::listBook(Book* book)
{
    if (!book) {
        cout << "Book not found.\n";
        return;
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11); // Bright cyan for heading

    cout << "\n\n" << setw(40) << "Book Details\n\n";

    SetConsoleTextAttribute(hConsole, 15); // Reset to default

    const int fieldWidth = 20;
    const int valueWidth = 50;
    const int totalWidth = fieldWidth + valueWidth + 2; // +2 for the "| " separator

    cout << "" << "\n";
    cout << std::string(totalWidth, '-') << "\n";

    cout << std::left << std::setw(fieldWidth) << "Book ID"
        << "| " << setw(valueWidth) << book->bookID << "\n";
    cout << left << setw(fieldWidth) << "Title"
        << "| " << setw(valueWidth) << book->bookTitle << "\n";
    cout << left << setw(fieldWidth) << "Author"
        << "| " << setw(valueWidth) << book->bookAuthor << "\n";
    cout << left << setw(fieldWidth) << "Genre"
        << "| " << setw(valueWidth) << book->genre << "\n";
    cout << left << setw(fieldWidth) << "Availability"
        << "| " << setw(valueWidth) << (book->isAvailable ? "Available" : "Not Available") << "\n";
    cout << string(totalWidth, '-') << "\n";

    // Print summary separately
    cout << "\nSummary:\n" << book->summary << "\n";

}

Book* BookHashTableByID::searchByID(string bookID)
{

    int index = hash_value(bookID);

    for (Book* iterNode = bookIDTable[index]; iterNode; iterNode = iterNode->hashNextByID) {

        if (iterNode->bookID == bookID) {

            this->listBook(iterNode);
            return iterNode;
        }
    }

    cout << "\n\n\n\t\tBook not Found" << endl;
}

void BookHashTableByID::borrowBook(string bookID)
{
    Book* book = this->searchByID(bookID);
    
    cout << "Do you want to borrow this book (y / n): ";
    string option;
    cin >> option;

    bool isRunning = true;

    while (isRunning) {

        if (option == "y") {

            if (!book->isAvailable) {

                cout << "\n\n\t This book is not available\n" << endl;
            }
            else {

                book->isAvailable = false;
            }
            isRunning = false;
        }
        else if (option == "n") {

            isRunning = false;
        }
        else {

            cout << "\n\n\t\tEnter correct option" << endl;
        }

    }
}

void BookHashTableByID::returnBook(string bookID)
{
    Book* book = this->searchByID(bookID);

    if (book->isAvailable) {

        cout << "\n\n\tThis book is available\n" << endl;
    }
    else {

        book->isAvailable = true;
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

            Book* newBook = doublyLinkedBooks->insertBook(bookID, bookTitle, bookAuthor, summary, genre, ((isAvailable == "true") ? 1 : 0));

            this->addBookInTable(newBook);
            this->bookHashTableByBookTitle->addBookInTable(newBook);
            this->bookHashTableByBookAuthor->addBookInTable(newBook);

        }
    }
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

            cout << iterNode->bookID << "   "
                << iterNode->bookTitle << "   "
                << iterNode->bookAuthor << "   "
                << iterNode->summary << "   "
                << iterNode->genre << "    "
                << ((iterNode->isAvailable) ? "True" : "False") << "\n" << endl;
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
    bool isFound = false;

    int index = hash_value(bookAuthor);

    for (Book* iterNode = this->bookAuthorTable[index]; iterNode; iterNode = iterNode->hashNextByAuthor) {

        if (iterNode->bookAuthor == bookAuthor) {

            cout << iterNode->bookID << "   "
                << iterNode->bookTitle << "   "
                << iterNode->bookAuthor << "   "
                << iterNode->summary << "   "
                << iterNode->genre << "    "
                << ((iterNode->isAvailable) ? "True" : "False") << "\n" << endl;

            isFound = true;
        }
    }

    if (!isFound) {

        cout << "\n\n\t\tBook Not Found" << endl;
    }
}
