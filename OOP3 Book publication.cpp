#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void add() {
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Price: ";
        cin >> price;
    }
    void display() const {
        cout << "Title: " << title << ", Price: " << price;
    }
};

class Book : public Publication {
    int pageCount;
public:
    void addBook() {
        add();
        cout << "Enter Page Count: ";
        cin >> pageCount;
        if (pageCount <= 0) {
            cout << "Invalid Page Count! Setting to 0.\n";
            pageCount = 0;
        }
    }
    void displayBook() const {
        display();
        cout << ", Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
    float playTime;
public:
    void addTape() {
        add();
        cout << "Enter Play Time (minutes): ";
        cin >> playTime;
        if (playTime <= 0) {
            cout << "Invalid Play Time! Setting to 0.\n";
            playTime = 0;
        }
    }
    void displayTape() const {
        display();
        cout << ", Play Time: " << playTime << " min\n";
    }
};

int main() {
    Book books[10];
    Tape tapes[10];
    int bCount = 0, tCount = 0, choice;

    do {
        cout << "\n1. Add Book\n2. Add Tape\n3. Display Books\n4. Display Tapes\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            books[bCount++].addBook();
            break;
        case 2:
            tapes[tCount++].addTape();
            break;
        case 3:
            cout << "\nBooks:\n";
            for (int i = 0; i < bCount; i++) books[i].displayBook();
            break;
        case 4:
            cout << "\nTapes:\n";
            for (int i = 0; i < tCount; i++) tapes[i].displayTape();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    } while (true);

    return 0;
}

