#include <iostream>
#include <string>
using namespace std;
class Node {
public:
    string studentName;
    int priority;
    Node* next;
};
class BookReservationQueue {
private:
    Node* head;
    string bookName;
    //INSERT NODE ACCORDING TO PRIORITY
    void InsertNode(Node* newNode) {  
        if (head == nullptr || newNode->priority > head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head; 
            while (temp->next != nullptr &&
                temp->next->priority >= newNode->priority) {
                temp = temp->next;
            } 
            newNode->next = temp->next;
            temp->next = newNode;
        }
    } 
public:
    BookReservationQueue(string name) {
        head = nullptr;
        bookName = name;
    } 
    //ADD A STUDENT TO RESERVATION QUEUE
    void AddStudent(string name, int priority) {
        Node* newNode = new Node; 
        newNode->studentName = name;
        newNode->priority = priority;
        newNode->next = nullptr; 
        InsertNode(newNode); 
        cout << name << " added to " << bookName << " Queue." << endl;
    }
    //REMOVE A STUDENT IF CANCEL
    void RemoveStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation queue is empty!" << endl;
            return;
        } 
        if (head->studentName == name) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            cout << name << " Cancelled Reservation." << endl;
            return;
        }

        Node* temp = head; 
        while (temp->next != nullptr &&
            temp->next->studentName != name) {
            temp = temp->next;
        } 
        if (temp->next == nullptr) {
            cout << "Student Not Found!" << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode; 
            cout << name << " Cancelled Reservation." << endl;
        }
    }
    //UPDATE STUDENT PRIORITY
    void UpdatePriority(string name, int newPriority) {
        Node* temp = head;
        Node* previous = nullptr; 
        while (temp != nullptr && temp->studentName != name) {
            previous = temp;
            temp = temp->next;
        } 
        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }
        //REMOVE STUDENT FROM CURRENT POSITION
        if (previous == nullptr) {
            head = temp->next;
        }
        else {
            previous->next = temp->next;
        }
        //UPDATE PRIORITY & INSERT AT CORRECT POSITION 
        temp->priority = newPriority;
        temp->next = nullptr; 
        InsertNode(temp); 
        cout << name << "'s Priority Updated Successfully!" << endl;
    }
    //DISPLAY
    void DisplayQueue() {
        cout << "Book: " << bookName << endl; 
        if (head == nullptr) {
            cout << "No reservations!" << endl;
            return;
        } 
        Node* temp = head; 
        while (temp != nullptr) {
            cout << temp->studentName << " ("; 
            if (temp->priority == 3)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << ") -> "; 
            temp = temp->next;
        } 
        cout << "NULL" << endl;
    }
    //COUNT TOTAL STUDENT
    void CountStudents() {
        int count = 0;
        Node* temp = head; 
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        } 
        cout << "Total reservations for " << bookName << ": " << count << endl;
    }
    //SERVE THE STUDENT AT THE FRONT WHEN BOOK IS RETURNED 
    void ServeNextStudent() {
        if (head == nullptr) {
            cout << "No student is waiting for this book!" << endl;
            return;
        } 
        Node* temp = head;
        head = head->next; 
        cout << "Book returned! " << temp->studentName << " can now borrow " << bookName << "." << endl; 
        delete temp;
    }
    //DESTRUCTOR
    ~BookReservationQueue() {
        Node* temp; 
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
}; 
int main() {
     
    BookReservationQueue book1("Data Structures");
    BookReservationQueue book2("Database Systems");
     
    cout << "--- DATA STRUCTURES ---" << endl;

    book1.AddStudent("Ali", 1);
    book1.AddStudent("Sara", 2);
    book1.AddStudent("Ahmed", 3);

    book1.DisplayQueue();
     
    book1.UpdatePriority("Ali", 3);

    book1.DisplayQueue();
     
    book1.RemoveStudent("Sara");

    book1.DisplayQueue();
     
    book1.CountStudents();
     
    book1.ServeNextStudent();

    book1.DisplayQueue();
     
    cout << "--- DATABASE SYSTEMS ---" << endl;

    book2.AddStudent("Usman", 1);
    book2.AddStudent("Hina", 3);
    book2.AddStudent("Zain", 2);

    book2.DisplayQueue();
     
    book2.CountStudents();
     
    book2.ServeNextStudent();

    book2.DisplayQueue();

    return 0;
}
