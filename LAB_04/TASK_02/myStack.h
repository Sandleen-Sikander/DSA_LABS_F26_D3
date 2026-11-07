#pragma once
#include <iostream>
#include "AbstractStack.h"
using namespace std;
template <typename T>
class myStack : public AbstractStack<T> {
private:
	T* array;
	T* minArr;
	int maxSize;
	int size;
public:
	//CONSTRUCTOR
	myStack(int ms = 10) {
		maxSize = ms;
		size = 0;
		array = new T[maxSize]; 
		minArr = new T[maxSize];
	} 
	void push(T value) override {
		if (isFull()) {
			cout << "STACK IS FULL!" << endl;
			return;
		} 
		array[size] = value; 
		// Track the minimum element
		if (size == 0 || value < minArr[size - 1]) {
			minArr[size] = value;
		}
		else {
			minArr[size] = minArr[size - 1];
		} 
		size++; 
		cout << value << " pushed into stack. " << endl;
	}
	T pop() override {
		if (isEmpty()) {
			cout << "STACK IS EMPTY!" << endl;
			return -1;
		} size--;
		T Value = array[size];
		cout << Value << " popped from stack. " << endl;
		return Value;
	}
	T top() const override {
		if (isEmpty()) {
			cout << "STACK IS EMPTY!" << endl;
			return -1;
		}
		return array[size - 1];
	}
	bool isEmpty() const override {
		return size == 0;
	}
	bool isFull() const override {
		return size == maxSize;
	}
	void display() const {
		for (int i = size - 1; i >= 0; i--) {
			cout << array[i] << " ";
		}cout << endl;
	}
	T getMin() const {
		if (isEmpty()) {
			cout << "STACK IS EMPTY!" << endl;
			return -1;
		}
		return minArr[size - 1];
	}
	~myStack() override {
		delete[] array;
		array = nullptr;
		delete[] minArr;
		minArr = nullptr;
	}
};

