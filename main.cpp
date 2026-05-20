#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book() {
        id = 0;
        title = "";
        author = "";
        isIssued = false;
    }

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        isIssued = false;
    }

    void display() {
        cout << "\nBook ID: " << id;
        cout << "\nTitle  : " << title;
        cout << "\nAuthor : " << author;
        cout << "\nStatus : " << (isIssued ? "Issued" : "Available") << endl;
        cout << "-------------------------\n";
    }
};

vector<Book> books;

void saveToFile() {
    ofstream file("books.dat");
    for (auto &b : books) {
        file << b.id << endl;
        file << b.title << endl;
        file << b.author << endl;
        file << b.isIssued << endl;
    }
    file.close();
}

void loadFromFile() {
    books.clear();
    ifstream file("books.dat");

    if (!file) return;

    Book b;
    while (file >> b.id) {
        file.ignore();
        getline(file, b.title);
        getline(file, b.author);
        file >> b.isIssued;
        file.ignore();

        books.push_back(b);
    }

    file.close();
}

void addBook() {
    Book b;
    b.input();
    books.push_back(b);
    saveToFile();
    cout << "\nBook Added Successfully!\n";
}

void displayBooks() {
    loadFromFile();

    if (books.empty()) {
        cout << "\nNo books available!\n";
        return;
    }

    for (auto &b : books) {
        b.display();
    }
}

void searchBook() {
    loadFromFile();
    string keyword;
    cin.ignore();

    cout << "Enter Title or Author to Search: ";
    getline(cin, keyword);

    bool found = false;

    for (auto &b : books) {
        if (b.title.find(keyword) != string::npos ||
            b.author.find(keyword) != string::npos) {
            b.display();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo matching books found!\n";
}

void issueBook() {
    loadFromFile();
    int id;
    cout << "Enter Book ID to Issue: ";
    cin >> id;

    bool found = false;

    for (auto &b : books) {
        if (b.id == id) {
            found = true;
            if (!b.isIssued) {
                b.isIssued = true;
                cout << "\nBook Issued Successfully!\n";
            } else {
                cout << "\nBook already issued!\n";
            }
        }
    }

    if (!found)
        cout << "\nBook not found!\n";

    saveToFile();
}

void returnBook() {
    loadFromFile();
    int id;

    cout << "Enter Book ID to Return: ";
    cin >> id;

    bool found = false;

    for (auto &b : books) {
        if (b.id == id) {
            found = true;
            if (b.isIssued) {
                b.isIssued = false;
                cout << "\nBook Returned Successfully!\n";
            } else {
                cout << "\nBook was not issued!\n";
            }
        }
    }

    if (!found)
        cout << "\nBook not found!\n";

    saveToFile();
}

int main() {
    int choice;

    loadFromFile();

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "\nThank you!\n"; break;
            default: cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
