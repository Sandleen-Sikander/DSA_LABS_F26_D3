#include <iostream>
using namespace std;
#include "AbstractStack.h"
#include "myStack.h"
int main()
{
    int size = 0;
    cout << "Enter Maximum Size of Stack: ";
    cin >> size;
    if (size <= 0) {
        cout << "INVALID VALUE! STACK SIZE MUST BE POSITIVE. " << endl;
        return 1;
    } 
    myStack<int> s1(size);
    int choice;
    int push;
    do {
        cout << "----- STACK MENU -----" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top Element" << endl;
        cout << "4. Check if Stack is Empty" << endl;
        cout << "5. Check if Stack is Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter Value to Push: ";
            cin >> push;
            s1.push(push);  
        }
        else if (choice == 2) { 
            cout << "Pop Element: " << s1.pop() << endl;  
        }
        else if (choice == 3) {
            cout << "Top Element: " << s1.pop() << endl;
        }
        else if (choice == 4) {
            if (s1.isEmpty()) {
                cout << "STACK IS EMPTY! " << endl;
            }
            else {
                cout << "NO, STACK IS NOT EMPTY. " << endl;
            }
        }
        else if (choice == 5) {
            if (s1.isFull()) {
                cout << "STACK IS FULL! " << endl;
            }
            else {
                cout << "NO, STACK IS NOT FULL. " << endl;
            }
        }
        else if (choice == 6) {
            cout << "Array Elements: ";
            s1.display();
        }
        else if (choice == 7) { 
            cout << "Minimum Element: " << s1.getMin() << endl;
        }
    } while (choice != 0);
    return 0;
}
 