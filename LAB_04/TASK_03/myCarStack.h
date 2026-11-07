#pragma once
#include<iostream>
#include<string>
using namespace std;
class myCarStack {
private:
	string cars[8];
	int maxSize;
	int size;
public:
	//CONSTRUCTOR
	myCarStack() {
		maxSize = 8;
		size = 0;
	}
	bool isEmpty() const {
		return size == 0;
	}
	bool isFull() const {
		return size == maxSize;
	}
	int get_Size() const {
		return size;
	}
	void push(string carNumber) {
		if (isFull()) {
			cout << "PARKING IS FULL!" << endl;
			return;
		}
		cars[size] = carNumber;
		size++;
		cout << "Car " << carNumber << " Parked Successfully." << endl;
	}
	string pop() {
		if (isEmpty()) {
			cout << "PARKING IS EMPTY!" << endl;
			return " ";
		}
		size--;
		return cars[size];
	}
	void ViewTop() const {
		if (isEmpty()) {
			cout << "NO CAR IS PARKED!" << endl;
			return;
		}
		cout << "Top Car: " << cars[size - 1] << endl;
	}
	void Display() {
		if (isEmpty()) {
			cout << "PARKING LOT IS EMPTY!" << endl;
			return;
		}
		cout << "PARKED CARS: ";
		for (int i = size - 1; i >= 0; i--) {
			cout << cars[i] << " ";
		}cout << endl;
	}
	bool search(string carNumber) {
		if (isEmpty()) {
			cout << "NO CAR IS PARKED!" << endl;
			return false;
		}
		for (int i = 0; i < size; i++) {
			if (cars[i] == carNumber) {
				return true;
			}
		}return false;
	}
	void removeCar(string carNumber) {
		myCarStack temp;
		string currentCar; 
		// Move cars above the desired car to temporary stack
		while (!isEmpty() && cars[size - 1] != carNumber) {
			currentCar = pop();
			temp.push(currentCar);
		} 
		// Remove the desired car
		if (!isEmpty()) {
			pop();
			cout << "Car " << carNumber << " removed from the parking lot." << endl;
		} 
		// Restore the temporarily removed cars
		while (!temp.isEmpty()) {
			currentCar = temp.pop();
			push(currentCar);
		}
	}
};

