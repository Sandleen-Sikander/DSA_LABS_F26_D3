#pragma once
#include<iostream>
using namespace std;
template<class T>
class QueueTwoStack {
private:
	T* stack1;
	T* stack2;
	int maxSize; 
	int count;
	int top1;
	int top2;
public:
	QueueTwoStack(int size = 10) {
		maxSize = size; 
		count = 0;
		top1 = -1;
		top2 = -1;
		stack1 = new T[maxSize];
		stack2 = new T[maxSize];
	}
	~QueueTwoStack() {
		delete[] stack1;
		delete[] stack2;
	}
	bool isEmpty() {
		return count == 0;
	}
	bool isFull() {
		return count == maxSize;
	}
	void enQueue(T value) {
		if (isFull()) {
			cout << "Queue OverFlow" << endl;
		}
		else {
			top1++;
			stack1[top1] = value;
			count++;
			cout << "Element Inserted Successfully." << endl;
		}
	}
	void transfer() {
		if (isEmpty()) {
			cout << "Queue UnderFlow" << endl; 
		}
		else {
			if (top2 == -1) {
				for (int i = top1; i >= 0; i--) {
					top2++;
					stack2[top2] = stack1[i];
				}
				top1 = -1;
			}
		}
	}
	T deQueue() {
		if (isEmpty()) {
			cout << "Queue UnderFlow" << endl;
			return T();
		} 
		else {
			transfer();
			T temp = stack2[top2];
			top2--;
			count--;
			return temp;
		}
	}
	T front() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return T();
		} 
		else {
			transfer();
			return stack2[top2];
		}
	}
	void display() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return;
		} 
		cout << "---Queue Elements---" << endl;
		cout << "Stack 2: ";
		// Display stack2
		for (int i = top2; i >= 0; i--) {
			cout << stack2[i] << " ";
		} cout << endl;
		cout << "Stack 1: ";
		// Display stack1
		for (int i = 0; i <= top1; i++) {
			cout << stack1[i] << " ";
		}cout << endl;
	}
};

