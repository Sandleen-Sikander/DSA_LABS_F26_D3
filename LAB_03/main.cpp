#include <iostream>
#include "List.h"
#include "MyList.h"
#include "CustomList.h" 
using namespace std; 
int main()
{
    int capacity; 
    cout << "Enter maximum capacity of List: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid Capacity." << endl;
        return 0;
    }

    CustomList<int> list(capacity); 
    int choice;
    int value;
    int index;
    int rotations;
    cout << endl;
    do
    {
        cout << "========== GENERIC LIST MENU ==========" << endl;
        cout << "1. Add element at beginning" << endl;
        cout << "2. Add element at end" << endl;
        cout << "3. Remove element from end" << endl;;
        cout << "4. Remove element from beginning" << endl;
        cout << "5. Insert element at index" << endl;
        cout << "6. Display last element" << endl;
        cout << "7. Search for an element" << endl;
        cout << "8. Check whether list is empty" << endl;
        cout << "9. Check whether list is full" << endl;
        cout << "10. Display size" << endl;
        cout << "11. Sum of prime numbers" << endl;
        cout << "12. Second maximum even number" << endl;
        cout << "13. Second minimum odd number" << endl;
        cout << "14. Display duplicates" << endl;
        cout << "15. Rotate clockwise" << endl;
        cout << "16. Rotate anti-clockwise" << endl;
        cout << "17. Display list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: "; 
        cin >> choice; 
        if (choice == 1)  {
            cout << "Enter value: ";
            cin >> value; 
            if (list.full())
                cout << "List is full." << endl;
            else {
                list.addElementAtFirstIndex(value);
                cout << "Element added." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;

            if (list.full()) {
                cout << "List is full." << endl;
            }
            else {
                list.addElementAtLastIndex(value);
                cout << "Element added." << endl;
            }
        }
        else if (choice == 3) {
            if (list.empty()) {
                cout << "List is empty." << endl;
            }
            else { 
                cout << "Removed element: " << list.removeElementFromEnd() << endl;
            }
        }
        else if (choice == 4)  {
            if (list.empty()) {
                cout << "List is empty." << endl;
            }
            else {
                list.removeElementFromStart();
                cout << "First element removed." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Enter index: ";
            cin >> index;

            cout << "Enter value: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Element inserted successfully." << endl;
            else
                cout << "Invalid index or list is full." << endl;
        }
        else if (choice == 6) {
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "Last element: " << list.last() << endl;
        }
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> value;

            if (list.search(value))
                cout << "Value found." << endl;
            else
                cout << "Value not found." << endl;
        }
        else if (choice == 8)
        {
            if (list.empty())
                cout << "List is empty." << endl;
            else
                cout << "List is not empty." << endl;
        }
        else if (choice == 9) {
            if (list.full())
                cout << "List is full." << endl;
            else
                cout << "List is not full." << endl;
        }
        else if (choice == 10) {
            cout << "Current size: " << list.size() << endl;
        }
        else if (choice == 11)
        {
            cout << "Sum of prime numbers: "
                << list.sum_ofPrime() << endl;
        }
        else if (choice == 12) {
            cout << "Second maximum even number: "
                << list.secondMaxEven() << endl;
        }
        else if (choice == 13) {
            cout << "Second minimum odd number: "
                << list.secondMinOdd() << endl;
        }
        else if (choice == 14)  {
            cout << "Duplicate values: ";
            list.printDuplicates();
        }
        else if (choice == 15) {
            cout << "Enter clockwise rotations: ";
            cin >> rotations; 
            list.rotateClockwaise(rotations); 
            cout << "List after clockwise rotation: ";
            list.display();
        }
        else if (choice == 16) {
            cout << "Enter anti-clockwise rotations: ";
            cin >> rotations; 
            list.rotateanitclockwaise(rotations); 
            cout << "List after anti-clockwise rotation: ";
            list.display();
        }
        else if (choice == 17) {
            cout << "Current list: ";
            list.display();
        }
        else if (choice == 0) {
            cout << "Program ended."<<endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}