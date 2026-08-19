#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    bool isCheckedOut;

public:
    Book(std::string bookTitle, std::string bookAuthor) {
        title = bookTitle;
        author = bookAuthor;
        isCheckedOut = false;
    }

    std::string getTitle() {
        return title;
    }

    bool getIsCheckedOut() {
        return isCheckedOut;
    }

    void setCheckedOut(bool status) {
        isCheckedOut = status;
    }

    void display() {
        std::cout << "\"" << title << "\" by " << author
            << (isCheckedOut ? " [Checked out]" : " [Available]") << std::endl;
    }
};

class Library {
private:
    std::string name;
    std::vector<Book> books; // vector of Book objects - classes using classes, again

public:
    Library(std::string libraryName) {
        name = libraryName;
    }

    void addBook(Book book) {
        books.push_back(book);
        std::cout << "Added: " << book.getTitle() << std::endl;
    }

    void checkOut(std::string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                if (books[i].getIsCheckedOut()) {
                    std::cout << title << " is already checked out." << std::endl;
                }
                else {
                    books[i].setCheckedOut(true);
                    std::cout << "Checked out: " << title << std::endl;
                }
                return;
            }
        }
        std::cout << title << " not found in " << name << "." << std::endl;
    }

    void listAllBooks() {
        std::cout << "\n" << name << " catalog:" << std::endl;
        for (int i = 0; i < books.size(); i++) {
            books[i].display();
        }
    }
};

int main() {
    Library myLibrary("City Library");

    myLibrary.addBook(Book("The Hobbit", "J.R.R. Tolkien"));
    myLibrary.addBook(Book("Dune", "Frank Herbert"));
    myLibrary.addBook(Book("1984", "George Orwell"));

    myLibrary.listAllBooks();

    myLibrary.checkOut("Dune");
    myLibrary.checkOut("Dune"); // try again - should say already checked out
    myLibrary.checkOut("Nonexistent Book"); // should say not found

    myLibrary.listAllBooks();

    return 0;
}
