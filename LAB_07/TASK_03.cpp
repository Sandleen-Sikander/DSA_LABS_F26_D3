#include<iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class SinglyLinkedList
{
private:
    Node* head;

public:
    //CONSTRUCTOR
    SinglyLinkedList() {
        head = nullptr;
    }
    //INSERT NODE AT SPECIFIC POSITION
    void InsertAtPosition(int value, int position) {
        Node* newNode = new Node; 
        newNode->data = value;
        newNode->next = nullptr;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head; 
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        } 
        if (temp == nullptr) {
            cout << "Invalid Position!" << endl;
            delete newNode;
            return;
        } 
        newNode->next = temp->next;
        temp->next = newNode; 
        cout << "Node Inserted Successfully!" << endl;
    }
    //DELETE NODE AT SPECIFIC POSITION
    void DeleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        } 
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            cout << "Node Deleted Successfully!" << endl;
            return;
        }

        Node* temp = head; 
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        } 
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid Position!" << endl;
            return;
        }

        Node* deleteNode = temp->next; 
        temp->next = deleteNode->next; 
        delete deleteNode; 
        cout << "Node Deleted Successfully!" << endl;
    }
    //SEARCH FOR AN ELEMENT
    void Search(int value) {
        Node* temp = head;
        int position = 1; 
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element Found at Position " << position << endl;
                return;
            } 
            temp = temp->next;
            position++;
        } 
        cout << "Element not Found!" << endl;
    }
    //COUNT TOTAL NODES
    void CountNodes() {
        Node* temp = head;
        int count = 0; 
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Total Number of Nodes: " << count << endl;
    }
    //DISPLAY
    void Display() {
        Node* temp = head; 
        if (head == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        } 
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        } 
        cout << "NULL" << endl;
    }
    //DESTRUCTOR
    ~SinglyLinkedList() {
        Node* temp; 
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{

    SinglyLinkedList list; 
    int choice = 0;
    int value = 0;
    int position = 0; 
    do {
        cout << "===== SINGLY LINKED LIST MENU =====" << endl;
        cout << "1. Insert at Specific Position" << endl;
        cout << "2. Delete at Specific Position" << endl;
        cout << "3. Search an Element" << endl;
        cout << "4. Count Total Nodes" << endl;
        cout << "5. Display List" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Value: ";
            cin >> value; 
            cout << "Enter Position: ";
            cin >> position; 
            list.InsertAtPosition(value, position);
        }
        else if (choice == 2) {
            cout << "Enter Position to Delete: ";
            cin >> position; 
            list.DeleteAtPosition(position);
        }
        else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value; 
            list.Search(value);
        }
        else if (choice == 4) {
            list.CountNodes();
        }
        else if (choice == 5) {
            list.Display();
        }
        else if (choice == 0) {
            cout << "Program Exicuted Successfully!" << endl;
        }
        else {
            cout << "Invalid Choice!" << endl;
        } 
    } while (choice != 0);

	return 0;
}