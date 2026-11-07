#include<iostream>
#include"myCarStack.h"
#include<string>
using namespace std;
int main()
{
	myCarStack parking;
	int choice;
	string carNumber;
    do {
        cout << "----- PARKING LOT MANAGEMENT SYSTEM -----" << endl;
        cout << "1. Park a New Car" << endl;
        cout << "2. Remove a Car" << endl;
        cout << "3. View Top Car" << endl;
        cout << "4. Display All Parked Cars" << endl;
        cout << "5. Total Cars Parked" << endl;
        cout << "6. Search for a Car" << endl;
        cout << "0. Exit" << endl; 
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Car NUmber: ";
            cin >> carNumber;
            parking.push(carNumber);
        } 
        else if (choice == 2) {
            cout << "Enter Car NUmber: ";
            cin >> carNumber;
            parking.removeCar(carNumber);
        }
        else if (choice == 3) {
            parking.ViewTop();
        }
        else if (choice == 4) {
            parking.Display();
        }
        else if (choice == 5) {
            cout << "Total Parked Cars: " << parking.get_Size() << endl;
        }
        else if (choice == 6) {
            cout << "Enter Car to Search: ";
            cin >> carNumber;
            if (search(carNumber)) {
                cout << "Car " << carNumber << " is present in the Parking lot." << endl;
            }
            else {
                cout << "Car " << carNumber << " is not present in the Parking lot." << endl;
            }
        }
        else if (choice == 0) {
            cout << "Exiting Parking Lot Management System." << endl;
        }    
    } while (choice != 0);
	return 0;
}