 Library Management System in C++

 Project Overview
The Library Management System is a console-based application developed using C++.  
It helps manage books, members, and borrowing records efficiently using Object-Oriented Programming (OOP) concepts and file handling.

This project allows users to add books, issue and return books, and search books by title or author.

---

 Features
- Add new books to the library
- Display all available books
- Search books by title or author
- Issue books to members
- Return books
- Track book availability

---

 Technologies Used
- C++
- Object-Oriented Programming (OOP)
- File Handling
- Console-based UI

---

 Project Structure
```
Library-Management-System/
│
├── main.cpp
├── README.md
├── books.dat
```

---

 OOP Concepts Used
- Classes and Objects
- Encapsulation
- Abstraction
- Member Functions

---

 File Handling
Book records are stored in:

```
books.dat
```

This ensures data persistence even after program exit.

---

 How to Run

 Compile
```bash
g++ main.cpp -o library
```

 Run

Windows:
```bash
library.exe
```

Linux / macOS:
```bash
./library
```

---

 Functionalities

 1. Add Book
Stores book details like:
- Book ID
- Title
- Author
- Availability status

 2. Display Books
Shows all books in the library system.

 3. Search Book
Search by:
- Title
- Author

4. Issue Book
Marks a book as issued if available.

 5. Return Book
Updates book status to available.

---

 Sample Output
```
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit

Enter choice: 1

Enter Book ID: 101
Enter Title: C++ Programming
Enter Author: Bjarne Stroustrup

Book Added Successfully!
```

---

 Advantages
- Simple and easy to use
- Efficient book management
- File-based persistent storage
- Demonstrates real-world library operations

---

Limitations
- No database support
- No login system
- Console-based interface only

---

 Future Enhancements
- Add admin login system
- Use database (MySQL)
- GUI-based application
- Fine system for late returns
- Barcode integration

---

 Author
Sudhiksha S

---

## 📄 License
This project is for educational and internship purposes only.
