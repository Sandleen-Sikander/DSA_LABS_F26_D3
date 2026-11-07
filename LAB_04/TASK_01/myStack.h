#pragma once
#include <iostream>
#include "AbstractStack.h"
using namespace std;
template <typename T>
class myStack : public AbstractStack<T> {
private:
	T* array;
	int maxSize;
	int size;
public:
	//CONSTRUCTOR
	myStack(int ms = 10) {
		maxSize = ms;
		int size = 0;
		array = new T[maxSize];  
	} 
	void push(T value) override {
		if (isFull()) {
			cout << "STACK IS FULL!" << endl;
		}
		array[size++] = value;
	}
	T pop() override {
		if (isEmpty()) {
			cout << "STACK IS EMPTY!" << endl;
			return -1;
		}
		return array[--size];
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
	~myStack() override {
		delete[] array;
		array = nullptr;
	}
};

