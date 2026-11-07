#include<iostream>
#include"QueueTwoStack.h"
using namespace std;  
int main() {
	QueueTwoStack<int> Q;
    int choice, element;
    do {
        cout << "---QUEUE USING TWO STACKS---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl; 
        cout << "----------------------------" << endl;
        cout << "Enter choice: ";
        cin >> choice;  
        if (choice == 1) {
               cout << "Enter Element: ";
               cin >> element;
               Q.enQueue(element);
        }
        else if (choice == 2) {
            cout << "Removed Element: " << Q.deQueue() << endl;
        }
        else if (choice == 3) {
            cout << "Front Element: " << Q.front() << endl;
        }
        else if (choice == 4) {
            Q.display();
        }
        else if (choice == 0) {
            cout << "Program Exited!" << endl;
        } 
    } while (choice != 0);

	return 0;
}