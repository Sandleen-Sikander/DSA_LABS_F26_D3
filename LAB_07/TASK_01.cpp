#include<iostream>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class singlyLinkedList {
private:
	Node* head;
public:
	//CONSTRUCTOR
	singlyLinkedList() {
		head = nullptr;
	}
	void CreateNode(int value) {
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
	void Display() {
		Node* temp = head; 
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		} 
		cout << "NULL" << endl;
	}
};
int main()
{
	singlyLinkedList list;
	list.CreateNode(10);
	list.CreateNode(39);
	list.CreateNode(75);
	cout << "Singly Linked List: ";
	list.Display();

	return 0;
}