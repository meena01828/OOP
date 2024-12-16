#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    string name;
    int quantity, cost, code;
    
    bool operator==(const Item& i) { return code == i.code; }
    bool operator<(const Item& i) { return cost < i.cost; }
};

vector<Item> itemList;

void insertItem() {
    Item item;
    cout << "Enter Name, Quantity, Cost, Code: ";
    cin >> item.name >> item.quantity >> item.cost >> item.code;
    itemList.push_back(item);
}

void displayItems() {
    if (itemList.empty()) {
        cout << "No items to display.\n";
        return;
    }
    for (size_t i = 0; i < itemList.size(); ++i) {
        cout << "Name: " << itemList[i].name
             << "\nQuantity: " << itemList[i].quantity
             << "\nCost: " << itemList[i].cost
             << "\nCode: " << itemList[i].code << endl;
    }
}

void searchItem() {
    int code;
    cout << "Enter Item Code to search: ";
    cin >> code;
    bool found = false;
    for (size_t i = 0; i < itemList.size(); ++i) {
        if (itemList[i].code == code) {
            cout << "Item Found: " << itemList[i].name << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Item not found.\n";
}

void deleteItem() {
    int code;
    cout << "Enter Item Code to delete: ";
    cin >> code;
    for (size_t i = 0; i < itemList.size(); ++i) {
        if (itemList[i].code == code) {
            itemList.erase(itemList.begin() + i);
            cout << "Item deleted.\n";
            return;
        }
    }
    cout << "Item not found.\n";
}

void sortItems() {
    sort(itemList.begin(), itemList.end());
    cout << "Items sorted by cost.\n";
    displayItems();
}

int main() {
    int choice;
    do {
        cout << "\n*** Menu ***"
             << "\n1. Insert"
             << "\n2. Display"
             << "\n3. Search"
             << "\n4. Sort by Cost"
             << "\n5. Delete"
             << "\n6. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: insertItem(); break;
        case 2: displayItems(); break;
        case 3: searchItem(); break;
        case 4: sortItems(); break;
        case 5: deleteItem(); break;
        case 6: cout << "Exiting program.\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

