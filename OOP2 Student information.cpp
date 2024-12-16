#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name, dob, bloodGroup, address, yearClass, mobile;
    int division;
    int rollNo;

public:
    friend class Faculty;

    Student() : rollNo(-1), division(-1), name(""), dob(""), bloodGroup(""), address(""), yearClass(""), mobile("") {}

    void addData() {
        cout << "\nEnter student information:\n";
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Roll No: ";
        cin >> rollNo;
        cout << "Division (1/2/3/4/5): ";
        cin >> division;
        cout << "Date of Birth: ";
        cin >> dob;
        cout << "Blood Group: ";
        cin >> bloodGroup;
        cout << "Phone Number: ";
        cin >> mobile;
        cin.ignore();
        cout << "Address: ";
        getline(cin, address);
        cout << "Year (SE/TE/BE): ";
        getline(cin, yearClass);
    }

    void display() const {
        cout << "\n-----------------------------------";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nYear: " << yearClass;
        cout << "\nDivision: " << division;
        cout << "\nDate of Birth: " << dob;
        cout << "\nBlood Group: " << bloodGroup;
        cout << "\nMobile: " << mobile;
        cout << "\nAddress: " << address;
        cout << "\n-----------------------------------";
    }

    static void header() {
        cout << "\n* * * Student Information System * * *\n";
    }
};

class Faculty {
public:
    
    void displayByDivision(const Student& student, int facultyDivision) {
        if (student.division == facultyDivision) {
            student.display();
        } else {
            cout << "\nInvalid Division for this Faculty.";
        }
    }
};

int main() {
    Student students[5];
    Faculty faculty;
    int choice, studentCount = 0;

    do {
        cout << "\n* * * Student Information System * * *";
        cout << "\n1. Add Student Information";
        cout << "\n2. Display All Students";
        cout << "\n3. Display Students by Faculty Division";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            if (studentCount < 5) {
                students[studentCount].addData();
                studentCount++;
            } else {
                cout << "\nStudent limit reached!";
            }
            break;

        case 2: 
            Student::header();
            for (int i = 0; i < studentCount; ++i) {
                students[i].display();
            }
            break;

        case 3: 
            int division;
            cout << "\nEnter Faculty Division: ";
            cin >> division;
            Student::header();
            for (int i = 0; i < studentCount; ++i) {
                faculty.displayByDivision(students[i], division);
            }
            break;

        case 4: 
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid choice. Please try again.";
        }
    } while (choice != 4);

    return 0;
}

