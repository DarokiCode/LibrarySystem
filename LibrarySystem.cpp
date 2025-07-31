#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;
    string dateAdded;

public:
    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdded = date;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "Availability: " << (available ? "Available" : "Borrowed") << endl;
        cout << "------------------------" << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    bool returnBook() {
        if (!available) {
            available = true;
            return true;
        }
        return false;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }
};

// Sort books in ascending order of ISBN
void sortBookData(Book books[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (books[j].getISBN() > books[j + 1].getISBN()) {
                swap(books[j], books[j + 1]);
            }
        }
    }
}

int main() {
    const int SIZE = 5;
    Book library[SIZE];

    library[0].setBookDetails("Naruto manga", "Masashi Kishimoto", "003", true, "07-12-2022");
    library[1].setBookDetails("Coraline", "Neil Gaiman", "002", true, "23-05-2023");
    library[2].setBookDetails("The Lord of the Rings", "J.R.R. Tolkien", "005", true, "31-08-2021");
    library[3].setBookDetails("One Hundred Years of Solitude", "Gabriel Garcia Marquez", "001", true, "02-01-2020");
    library[4].setBookDetails("One Piece manga", "Eiichiro Oda", "004", true, "5-11-2023");

    int choice;
    string inputISBN;

    while (true) {
        cout << "\nLibrary System Menu:\n";
        cout << "1. Borrow a Book\n";
        cout << "2. Return a Book\n";
        cout << "3. Exit\n";
        cout << "4. Display All Books (sorted by ISBN)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        if (choice == 4) {
            sortBookData(library, SIZE);
            cout << "\nBooks sorted by ISBN:\n";
            for (int i = 0; i < SIZE; i++) {
                library[i].displayBookDetails();
            }
            continue;
        }

        cout << "Enter ISBN: ";
        cin >> inputISBN;

        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                if (choice == 1) {
                    if (library[i].borrowBook()) {
                        cout << "Book borrowed successfully!" << endl;
                    } else {
                        cout << "Error: Book is already borrowed." << endl;
                    }
                } else if (choice == 2) {
                    if (library[i].returnBook()) {
                        cout << "Book returned successfully!" << endl;
                    } else {
                        cout << "Error: Book is already available." << endl;
                    }
                } else {
                    cout << "Invalid option." << endl;
                }
                library[i].displayBookDetails();
                break;
            }
        }

        if (!found) {
            cout << "Error: Book with ISBN " << inputISBN << " not found." << endl;
        }
    }

    return 0;
}
