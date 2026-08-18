#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    bool isCheckedOut;

    Book(std::string bookTitle) {
        title = bookTitle;
        isCheckedOut = false;
    }
};

class Library {
public:
    std::string name;

    Library(std::string libraryName) {
        name = libraryName;
    }

    // This function takes a Book object as a parameter - classes using classes
    void checkOut(Book& book) {
        if (book.isCheckedOut) {
            std::cout << book.title << " is already checked out." << std::endl;
        }
        else {
            book.isCheckedOut = true;
            std::cout << "Checked out: " << book.title << " from " << name << std::endl;
        }
    }
};

int main() {
    Library centralLibrary("Central Library");
    Book book1("The Hobbit");

    centralLibrary.checkOut(book1);
    centralLibrary.checkOut(book1); // try again - should say already checked out

    return 0;
}
