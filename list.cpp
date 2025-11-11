#include<iostream>
using namespace std;

class list {
    int arr[5], count = 0, l = 5;

    bool IsFull() {
        if (count == l) {
            return true;
        } else {
            return false;
        }
    }

    bool IsEmpty() {
        if (count == 0) {
            return true;
        } else {
            return false;
        }
    }

public:

    void insert_at_start(int value) {
        if (IsFull()) {
            cout << "List is full!" << endl;
        } 
        else if (IsEmpty()) {
            cout << "Element Inserted!" << endl;
            arr[0] = value;
            count++; // ✅ Fixed (was missing)
        } 
        else {
            cout << "Your Element Inserted At Start!" << endl;
            for (int i = count; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            count++;
        }
    }

    bool insert_at_end(int value) {
        if (count < l) {
            arr[count++] = value;
            cout << "Element inserted at end!" << endl;
            return true;
        } else {
            cout << "List is full!" << endl;
            return false;
        }
    }

    void insert_at_any_location(int value, int loc) {
        if (IsFull()) {
            cout << "List is full!" << endl;
        } 
        else if (loc == 1) {
            insert_at_start(value);
        } 
        else if (loc == count + 1) {
            insert_at_end(value);
        } 
        else if (loc > 1 && loc <= count) {
            for (int i = count; i >= loc; i--) {  // ✅ Fixed loop condition
                arr[i] = arr[i - 1];
            }
            arr[loc - 1] = value;
            count++;
            cout << "Element inserted at location " << loc << "!" << endl;
        } 
        else {
            cout << "Invalid location!" << endl;
        }
    }

    bool dell_at_start() {
        if (count > 0) {
            for (int i = 0; i < count - 1; i++) {
                arr[i] = arr[i + 1];
            }
            count--;
            cout << "Deleted element from start!" << endl;
            return true;
        } else {
            cout << "List is empty!" << endl;
            return false;
        }
    }

    bool dell_at_end() {
        if (count == 0) {
            cout << "List is empty!" << endl;
            return false;
        } else {
            count--;
            cout << "Deleted element from end!" << endl;
            return true;
        }
    }

    void dell_at_any_location(int loc) {
        if (IsEmpty()) {
            cout << "List is empty!" << endl;
        } 
        else if (loc == 1) {
            dell_at_start();
        } 
        else if (loc == count) {
            dell_at_end();
        } 
        else if (loc > 1 && loc < count) {
            for (int i = loc - 1; i < count - 1; i++) {  // ✅ Fixed loop
                arr[i] = arr[i + 1];
            }
            count--;
            cout << "Deleted element at location " << loc << "!" << endl;
        } 
        else {
            cout << "Invalid location!" << endl;
        }
    }

    void display() {
        if (IsEmpty()) {
            cout << "List is empty!" << endl;
        } 
        else {
            cout << "Current List: ";
            for (int i = 0; i < count; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    list l;

    l.insert_at_start(10);
    l.insert_at_start(20);
    l.insert_at_end(30);
    l.insert_at_any_location(40, 2);
    l.insert_at_any_location(50, 5);

    cout << endl;
    l.display();
    cout << endl;

    l.dell_at_start();
    l.dell_at_end();
    l.dell_at_any_location(2);

    cout << endl;
    l.display();

    return 0;
}