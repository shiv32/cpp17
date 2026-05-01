#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// ========================
// 1️⃣ Simple Classes
// ========================
class Book {
    string title;
public:
    Book(string t) : title(move(t)) {}
    string getTitle() const { return title; }
};

class Section {
    string name;
public:
    Section(string n) : name(move(n)) {}
    string getName() const { return name; }
};

// ========================
// 2️⃣ Aggregation Example
// Library HAS many Books (but doesn’t own them strictly)
// ========================
class Library {
    vector<Book*> books;                  // Aggregation
    vector<unique_ptr<Section>> sections; // Composition
public:
    void addBook(Book* b) {               // Library uses existing Book objects
        books.push_back(b);
    }

    void addSection(string name) {        // Composition: Library owns Section
        sections.push_back(make_unique<Section>(name));
    }

    void showBooks() const {
        cout << "\nBooks in Library:\n";
        for (auto* b : books)
            cout << " - " << b->getTitle() << '\n';
    }

    void showSections() const {
        cout << "\nSections in Library:\n";
        for (auto& s : sections)
            cout << " - " << s->getName() << '\n';
    }
};

// ========================
// 3️⃣ Association Example
// Member is associated with Book (borrows relationship)
// ========================
class Member {
    string name;
    Book* borrowedBook = nullptr; // Association (non-owning)
public:
    Member(string n) : name(move(n)) {}

    void borrow(Book* b) { borrowedBook = b; }
    void showBorrowedBook() const {
        if (borrowedBook)
            cout << name << " borrowed \"" << borrowedBook->getTitle() << "\"\n";
        else
            cout << name << " hasn't borrowed any book.\n";
    }
};

// ========================
// 4️⃣ Dependency Example
// Librarian depends on Book temporarily to perform action
// ========================
class Librarian {
public:
    void issueBook(Book& b) { // Dependency: uses Book temporarily
        cout << "Librarian issues \"" << b.getTitle() << "\"\n";
    }
};

// ========================
// 5️⃣ Main Demo
// ========================
int main() {
    // Independent objects
    Book b1("The C++ Programming Language");
    Book b2("Design Patterns");

    Library lib;
    lib.addSection("Programming");
    lib.addSection("Software Design");
    lib.addBook(&b1); // Aggregation
    lib.addBook(&b2);

    Member m("Shiv");
    m.borrow(&b2); // Association

    Librarian l;
    l.issueBook(b1); // Dependency

    // Show data
    lib.showSections();
    lib.showBooks();
    m.showBorrowedBook();

    // When Library is destroyed → Sections are destroyed (Composition)
    // But Books remain alive independently (Aggregation)
    return 0;
}
