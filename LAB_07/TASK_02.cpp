#include<iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class SinglyLinkedList {
private:
	Node* head;
public:
	//CONSTRUCTOR
	SinglyLinkedList() {
		head = nullptr;
	}
    //INSERT AT BEGINNING
    void InsertAtBeginning(int value) {
        Node* newNode = new Node; 
        newNode->data = value;
        newNode->next = head; 
        head = newNode;
    } 
	//INSERT AT END
    void InsertAtEnd(int value) {
        Node* newNode = new Node; 
        newNode->data = value;
        newNode->next = nullptr; 

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head; 
            while (temp->next != nullptr) {
                temp = temp->next;
            } 
            temp->next = newNode;
        }
    }
    //DELETE A NODE BY VALUE
    void DeleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is Empty!" << endl;
            return;
        } 
        if (head->data == value)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head; 
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        } 
        if (temp->next == nullptr) {
            cout << "Value Not Found!" << endl;
        }
        else {
            Node* deleteNode = temp->next; 
            temp->next = deleteNode->next; 
            delete deleteNode;
        }
    }
    //TRANSVERSE & DISPLAY
    void Display() {
        Node* temp = head; 
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

    list.InsertAtBeginning(10);
    list.InsertAtBeginning(20);

    list.InsertAtEnd(30);
    list.InsertAtEnd(40); 

    cout << "Original Linked List: ";
    list.Display();

    list.DeleteByValue(20);

    cout << "After Deleting 20: ";
    list.Display();

	return 0;
}