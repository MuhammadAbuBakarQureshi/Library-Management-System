# Library Management System

## Overview

This is a C++-based Library Management System designed for efficient book management in a university or school environment. The system includes both user and admin functionality, utilizing advanced data structures for optimized performance.

---
## Features

### Admin Functionalities
- View all books
- Add, update, delete books
- Find books
- Sort books by various criteria

### User Functionalities
- Register/Login
- List available books
- Search books
- Borrow and return books
- Sort books by ID, title, or author

---

## Login and Account System

- One hardcoded admin account
- User accounts are created dynamically and stored in `.txt` files
- Passwords are hashed and salted for security
- Email validation only allows `@gmail.com` addresses

---

## Data Structure Design

### Book Storage
- All book objects are stored in a **single Doubly Linked List**
- This structure keeps memory efficient and makes operations consistent

### Hash Tables for Fast Access
- Three separate hash tables are used for indexing by:
  - BookID
  - Title
  - Author
- Each hash table stores **addresses (pointers)** to the nodes in the doubly linked list, not full book objects
- This mimics how relational databases use **indexing**

### Collision Handling
- Handled using **chaining with singly linked lists** at each index

### Why This Design?
- Minimizes memory usage by storing one copy of each book
- Supports fast lookup, insertion, and deletion with average time complexity of **O(1)**
- Clean separation of concerns makes the codebase more maintainable and extendable

---

## Sorting

- Sorting is implemented using **Merge Sort**
- Supports sorting by:
  - BookID
  - Title
  - Author
- Time complexity: **O(n log n)**

---

## Book Availability

- A boolean flag is used to mark if a book is `available` or `borrowed`
- This simple system will be improved in future updates for better traceability

---

## Data Persistence

- Data (users and books) is stored using `.txt` files for session persistence
- Admin credentials are hardcoded since only one admin is required

---

## Technologies Used

- C++
- File Handling (`.txt`)
- Custom Data Structures:
  - Doubly Linked List
  - Singly Linked List (for collision resolution)
  - Hash Tables
- Terminal-based UI using console I/O

---

## Contribution

You can contribute if you want. Feel free to improve features, fix bugs, or add new functionalities.
