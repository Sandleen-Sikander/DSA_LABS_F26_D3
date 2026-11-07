#include <iostream>
#include <string>
using namespace std; 
struct PrintJob {
    int jobID;
    string userName;
    int pages;
}; 
class Circular_Queue {
private:
    PrintJob arr[5];
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
    void enqueue(PrintJob p) {
        if (isFull()) {
            cout << "Queue Overflow! No space for new print job." << endl;
            return;
        } 
        if (isEmpty()) {
            front = 0;
        } 
        rear = (rear + 1) % 5; 
        arr[rear] = p;
        count++; 
        cout << "Print job added successfully!" << endl;
    } 
    PrintJob dequeue() {
        PrintJob p; 
        if (isEmpty()) {
            cout << "Queue Underflow! No print job to process." << endl;
            return p;
        } 
        p = arr[front]; 
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % 5;
        } count--; 
        return p;
    } 
    void peek() {
        if (isEmpty()) {
            cout << "No pending print jobs." << endl;
            return;
        } 
        cout << "----NEXT PRINT JOB----" << endl;
        cout << "Job ID: " << arr[front].jobID << endl;
        cout << "User Name: " << arr[front].userName << endl;
        cout << "Total Pages: " << arr[front].pages << endl;
    } 
    void display() {
        if (isEmpty()) {
            cout << "No pending print jobs." << endl;
            return;
        } 
        cout << endl << "---ALL PENDING PRINT JOBS---" << endl; 
        int i = front; 
        for (int j = 0; j < count; j++) {
            cout << endl << "Job ID: " << arr[i].jobID << endl;
            cout << "User Name: " << arr[i].userName << endl;
            cout << "Total Pages: " << arr[i].pages << endl; 
            i = (i + 1) % 5;
        }
    }
    int totalJobs() {
        return count;
    }
};

int main() {
    Circular_Queue q;
    PrintJob p;
    int choice;

    do {
        cout << "----- PRINTER QUEUE MANAGEMENT SYSTEM -----" << endl;
        cout << "1. Submit a New Print Job" << endl;
        cout << "2. Process the Next Print Job" << endl;
        cout << "3. Display the Next Print Job" << endl;
        cout << "4. Display All Pending Print Jobs" << endl;
        cout << "5. Show Total Pending Print Jobs" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Job ID: ";
            cin >> p.jobID;

            cout << "Enter User Name: ";
            cin >> p.userName;

            cout << "Enter Total Pages: ";
            cin >> p.pages;

            q.enqueue(p);
        }
        else if (choice == 2) {
            if (!q.isEmpty()) {
                p = q.dequeue(); 
                cout <<"Print Job Processed Successfully!" << endl;
                cout << "Job ID: " << p.jobID << endl;
                cout << "User Name: " << p.userName << endl;
                cout << "Total Pages: " << p.pages << endl;
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
            cout << "Total Pending Print Jobs: "
                << q.totalJobs() << endl;
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