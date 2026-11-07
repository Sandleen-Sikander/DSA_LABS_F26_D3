#include<iostream>
#include"AbstractQueue.h"
#include"myQueue.h"
using namespace std;
int main()
{
	myQueue<int> Q;
	int choice = 0;
	int element = 0;
	do {
		cout << "---- LINEAR QUEUE ----" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Show Front" << endl;
		cout << "4. Check If Queue is Empty" << endl;
		cout << "5. Check If Queue is Full" << endl;
		cout << "6. Display" << endl;
		cout << "0. Exit" << endl;
		cout << "----------------------" << endl;
		cout << "Your Choice: ";
		cin >> choice;
		if (choice == 1) {
			cout << "Enter Element to Enqueue: ";
			cin >> element;
			Q.enQueue(element);
			cout << "Element enQueued successfully." << endl;
		}
		else if (choice == 2) {  
			cout << "DeQueued Element: " << Q.deQueue() << endl;
		}
		else if (choice == 3) {
			cout << "Front Element: " << Q.front() << endl;
		}
		else if (choice == 4) {
			if (Q.isEmpty()) {
				cout << "Queue is Empty" << endl;
			}
			else {
				cout << "No, Queue is not Empty" << endl;
			}
		}
		else if (choice == 5) {
			if (Q.isFull()) {
				cout << "Queue is Full" << endl;
			}
			else {
				cout << "No, Queue is not Full" << endl;
			}
		}
		else if (choice == 6) {
			cout << "Queue Element: ";
			Q.display();
		}
		else if (choice == 0) {
			cout << "Program Execute sucessfully." << endl;
		}
	} while (choice != 0);
	return 0;
}