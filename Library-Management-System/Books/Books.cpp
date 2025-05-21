#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Books.h"

using namespace std;



BookHashTableByID::BookHashTableByID()
{
    this->doublyLinkedBooks = new DoublyLinkedBooks();
}

void BookHashTableByID::addBook(string bookTitle, string bookAuthor, string summary, string genre)
{

    Book* newBook = doublyLinkedBooks->insertBook("needed", bookTitle, bookAuthor, summary, genre);
    
    int index = hash_value(newBook->bookID);

    if (bookTable[index] == nullptr) {

        bookTable[index] = newBook;
        return;
    }

    for (Book* iterNode = bookTable[index]; iterNode; iterNode = iterNode->hashNext) {

        if (iterNode->hashNext == nullptr) {

            iterNode->hashNext = newBook;
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

                int index = hash_value(newBook->bookID);

                if (bookTable[index] == nullptr) {

                    bookTable[index] = newBook;
                }
                else {

                    for (Book* iterNode = bookTable[index]; iterNode; iterNode = iterNode->hashNext) {

                        if (iterNode->hashNext == nullptr) {

                            iterNode->hashNext = newBook;
                            break;
                        }
                    }
                }

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

    for (Book* iterNode = bookTable[index]; iterNode; iterNode = iterNode->hashNext) {

        if (iterNode->bookID == bookID) {

            cout << iterNode->bookTitle << endl
                << iterNode->bookAuthor << endl
                << iterNode->summary << endl
                << iterNode->genre << endl;
            return;
        }
    }

    cout << "\n\n\n\t\tBook not Found" << endl;
}

//void BookHashTableByID::write_file()
//{
//
//
//    string data = "";
//
//    data += std::to_string(Book::totalBooks);
//    data += ",\n";
//
//    for (int i = 0; i < 20; i++) {
//
//        Book* iterNode = bookTable[i];
//
//        if (iterNode == nullptr) {
//
//            data += "nullptr\n";
//            continue;
//        }
//
//        Book* ll_iterNode = iterNode;
//
//        while (ll_iterNode) {
//
//            data += ll_iterNode->bookID;
//            data += ",";
//            data += ll_iterNode->bookTitle;
//            data += ",";
//            data += ll_iterNode->bookAuthor;
//            data += ",";
//            data += ll_iterNode->summary;
//            data += ",";
//            data += ll_iterNode->genre;
//            /*data += ",";
//            data += ll_iterNode->isAvailable;*/
//
//            if (ll_iterNode->next == nullptr) {
//
//                data += ",nullptr\n";
//                break;
//            }
//            else {
//
//                data += ",next\n";
//            }
//
//            ll_iterNode = ll_iterNode->next;
//        }
//    }
//
//    fstream file;
//
//    file.open("books.csv", ios::out);
//
//    if (file.is_open()) {
//
//        file << data;
//        file.close();
//    }
//}
//
//void BookHashTableByID::read_file()
//{
//
//
//    fstream file;
//
//    file.open("books.csv", ios::in);
//
//    if (file.is_open()) {
//
//        int i = 0;
//
//        string data;
//
//        string firstLine;
//
//        if (getline(file, firstLine)) {
//
//            stringstream ss(firstLine);
//
//            string totalBooks;
//            getline(ss, totalBooks, ',');
//
//            Book::totalBooks = stoi(totalBooks);
//        }
//
//
//        while (getline(file, data)) {
//
//
//            if (data == "nullptr") {
//
//                i++;
//                continue;
//            }
//            else {
//
//                string bookID, bookTitle, bookAuthor, summary, genre, check;
//                //bool isAvailable;
//
//                stringstream ss(data);
//
//                getline(ss, bookID, ',');
//                getline(ss, bookTitle, ',');
//                getline(ss, bookAuthor, ',');
//                getline(ss, summary, ',');
//                getline(ss, genre, ',');
//
//                Book* newBook = new Book(bookID, bookTitle, bookAuthor, summary, genre);
//
//                getline(ss, check);
//
//                if (bookTable[i] == nullptr) {
//
//                    bookTable[i] = newBook;
//                    if (check == "nullptr") i++;
//                    continue;
//                }
//
//                for (Book* iterNode = bookTable[i]; iterNode; iterNode = iterNode->next) {
//
//                    if (iterNode->next == nullptr) {
//
//                        iterNode->next = newBook;
//                        break;
//                    }
//                }
//
//                if (check == "nullptr") i++;
//
//
//            }
//        }
//    }
//
//}


// BOOK HASH TABLE BY BOOK TITLE

//void BookhashTableByBookTitle::insertBookID()
//{
//}
