#include <iostream>
#include <string>
using namespace std; 
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
}; 
class Circular_Queue {
private:
    Booking arr[5];
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
    void enqueue(Booking b) {
        if (isFull()) {
            cout << "Queue Overflow! No space for new booking." << endl;
            return;
        } 
        if (isEmpty()) {
            front = 0;
        } 
        rear = (rear + 1) % 5; 
        arr[rear] = b;
        count++; 
        cout << "Booking added successfully!" << endl;
    } 
    Booking dequeue() {
        Booking b; 
        if (isEmpty()) {
            cout << "Queue Underflow! No booking to cancel." << endl;
            return b;
        } 
        b = arr[front]; 
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % 5;
        } 
        count--; 
        return b;
    } 
    void peek() {
        if (isEmpty()) {
            cout << "No bookings available." << endl;
            return;
        } 
        cout << endl << "Next Booking:" << endl;
        cout << "Customer ID: " << arr[front].customerID << endl;
        cout << "Customer Name: " << arr[front].customerName << endl;
        cout << "Number of Tickets: " << arr[front].numberOfTickets << endl;
    } 
    void display() {
        if (isEmpty()) {
            cout << "No bookings available." << endl;
            return;
        } 
        cout  << "-----ALL CURRENT BOOKINGS-----"; 
        int i = front; 
        for (int j = 0; j < count; j++) {
            cout << endl << "Customer ID: " << arr[i].customerID << endl;
            cout << "Customer Name: " << arr[i].customerName << endl;
            cout << "Number of Tickets: " << arr[i].numberOfTickets << endl; 
            i = (i + 1) % 5;
        }
        cout << "-------------------------------" << endl;;
    } 
    int totalBookings() {
        return count;
    }
};

int main() {
    Circular_Queue q;
    Booking b;
    int choice;

    do {
        cout  << "----- CINEMA TICKET BOOKING SYSTEM -----" << endl;
        cout << "1. Book Tickets" << endl;
        cout << "2. Cancel the First Booking" << endl;
        cout << "3. Display the Next Booking" << endl;
        cout << "4. Display All Bookings" << endl;
        cout << "5. Show Total Number of Bookings" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Customer ID: ";
            cin >> b.customerID;

            cout << "Enter Customer Name: ";
            cin >> b.customerName;

            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;

            q.enqueue(b);
        }
        else if (choice == 2) {
            if (!q.isEmpty()) {
                b = q.dequeue(); 
                cout << "Booking Cancelled Successfully!" << endl;
                cout << "Customer ID: " << b.customerID << endl;
                cout << "Customer Name: " << b.customerName << endl;
                cout << "Number of Tickets: " << b.numberOfTickets << endl;
            }
            else {
                q.dequeue();
            }
        }
        else if (choice == 3) {
            q.peek();
        }
        else if (choice == 4) {
            q.display();
        }
        else if (choice == 5) {
            cout << "Total Number of Bookings: " << q.totalBookings() << endl;
        }
        else if (choice == 6) {
            cout << "Program Exited Successfully." << endl;
        }
        else {
            cout << "Invalid Choice! Try Again." << endl;
        }

    } while (choice != 6);

    return 0;
}