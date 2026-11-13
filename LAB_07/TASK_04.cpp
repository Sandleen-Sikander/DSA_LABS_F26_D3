#include <iostream>
using namespace std; 
class Node {
public:
    int patientID;
    Node* next;
}; 
class PatientQueue {
private:
    Node* head; 
public:
    //CONSTRUCTOR
    PatientQueue() {
        head = nullptr;
    }
    //ADD NEW PATIENT AT THE END 
    void AddPatient(int id) {
        Node* newNode = new Node;
        newNode->patientID = id;
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
        cout << "Patient " << id << " Added Successfully!" << endl;
    }
    //REMOVE A PATIENT BY ID
    void RemovePatient(int id) {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        //IF THE PATIENT AT BEGINNING
        if (head->patientID == id) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            cout << "Patient " << id << " Removed Successfully!" << endl;
            return;
        } 
        Node* temp = head; 
        while (temp->next != nullptr &&
            temp->next->patientID != id) {
            temp = temp->next;
        } 
        if (temp->next == nullptr) {
            cout << "Patient Not Found!" << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode; 
            cout << "Patient " << id << " Removed Successfully!" << endl;
        }
    }
    //DISPLAY
    void DisplayPatients() {
        if (head == nullptr) {
            cout << "No patients in the Queue!" << endl;
            return;
        } 
        Node* temp = head; 
        cout << "Current Patient Queue: "; 
        while (temp != nullptr) {
            cout << temp->patientID << " -> ";
            temp = temp->next;
        } 
        cout << "NULL" << endl;
    }
    //TOTAL PATIENTS
    void CountPatients() {
        int count = 0;
        Node* temp = head; 
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        } 
        cout << "Total Patients: " << count << endl;
    }
    //DESTRUCTOR
    ~PatientQueue() {
        Node* temp; 
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue queue;
 
    queue.AddPatient(101);
    queue.AddPatient(102);
    queue.AddPatient(103);
    queue.AddPatient(104);
     
    queue.DisplayPatients();
     
    queue.CountPatients();
     
    queue.RemovePatient(102);
     
    queue.DisplayPatients();
     
    queue.CountPatients();

    return 0;
}
