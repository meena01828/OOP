#include <iostream>
using namespace std;
#define SIZE 10

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;
    int intArr[SIZE];
    float floatArr[SIZE];

    cout << "***** Selection Sort Program *****" << endl;

    while (true) {
        cout << "\nMenu:";
        cout << "\n1. Sort Integer Array";
        cout << "\n2. Sort Float Array";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                
                cout << "Enter the number of integers: ";
                cin >> n;
                cout << "Enter the integer elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> intArr[i];
                }
                selectionSort(intArr, n);
                break;
            }
            case 2: {
            
                cout << "Enter the number of float elements: ";
                cin >> n;
                cout << "Enter the float elements: ";
                for (int i = 0; i < n; i++) {
                    cin >> floatArr[i];
                }
                selectionSort(floatArr, n);
                break;
            }
            case 3:
                
                cout << "Program exited successfully." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

