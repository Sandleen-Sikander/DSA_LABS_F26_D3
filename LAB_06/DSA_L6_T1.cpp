#include<iostream>
#include<string>
using namespace std;
struct Customer {
    string name;
    string transaction;
};
class Circular_Queue {
    Customer arr[5];
    int front;
    int rear;
    int count;
public:
    Circular_Queue() {
        front = -1;
        rear = -1;
        count = 0;
    }
    bool isEmpty() {
        return count == 0;
    } 
    bool isFull() {
        return count == 5;
    }
    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue Overflow! No space for new customer." << endl;
            return;
        } 
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % 5;
        arr[rear] = c;
        count++; 
        cout << "Customer added successfully!" << endl;
    }
    Customer dequeue() {
        Customer c;  
        if (isEmpty()) {
            cout << "Queue Underflow! No customer to serve." << endl;
            return c;
        } 
        c = arr[front]; 
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % 5;
        }count--;
        return c;
    }
    void display() {
        if (isEmpty()) {
            cout << "No customers are waiting." << endl;
            return;
        } 
        cout << "------Customers Waiting------ " << endl; 
        int i = front; 
        for (int j = 0; j < count; j++) {
            cout << "Customer Name: " << arr[i].name << endl;;
            cout << "Transaction Type: " << arr[i].transaction;
            cout << endl; 
            i = (i + 1) % 5;
        }
    }
    int totalCustomers() {
        return count;
    } 
};
int main() {
    Circular_Queue q;
    Customer c;
    int choice;
    do {
        cout << "----- BANK QUEUE MANAGEMENT SYSTEM -----" << endl;
        cout << "1. Add a Customer" << endl;
        cout << "2. Serve a Customer" << endl;
        cout << "3. Display All Waiting Customers" << endl;
        cout << "4. Show Total Waiting Customers" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Customer Name: ";
            cin >> c.name; 
            cout << "Enter Transaction Type: ";
            cin >> c.transaction; 
            q.enqueue(c);
        }
        else if (choice == 2) {
            if (!q.isEmpty()) {
                c = q.dequeue();

                cout << "Customer Served Successfully!" << endl;
                cout << "Customer Name: " << c.name << endl;
                cout << "Transaction Type: " << c.transaction << endl;
            }
            else {
                q.dequeue();
            }
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            cout << "Total Customers Waiting: " << q.totalCustomers() << endl;
        }
        else if (choice == 0) {
            cout << "Program Executed Successfully." << endl;
        }
        else {
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 0);
    return 0;
}