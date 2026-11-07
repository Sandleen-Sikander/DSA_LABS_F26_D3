#pragma once
#include<iostream>
#include"AbstractQueue.h"
using namespace std;
template <typename T>
class myQueue: public AbstractQueue<T> {
private:
	T* array;
	int maxSize; 
	int rear;
	int Front;
	int count;
public:
	myQueue(int size = 8) {
		maxSize = size;
		array = new T[maxSize];
		rear = 0;
		Front = 0;
		count = 0;
	}
	~myQueue() {
		delete[] array;
		array = nullptr;
	}
	void enQueue(T value) override {
		if (isFull()) {
			cout << "Queue OverFlow" << endl;
		}
		else {
			array[rear] = value;
			rear++;
			count++;
		}
	}
	T deQueue() override {
		if (isEmpty()) {
			cout << "Queue UnderFlow" << endl;
			return T();
		}
		else {
			T temp = array[Front];
			Front++;
			count--;
			return temp;
		}
	}
	T front() const override {
		if (isEmpty()) {
			cout << "Empty Queue" << endl;
			return T();
		}
		else {
			return array[Front];
		}
	}
	bool isEmpty() const override {
		return count == 0;
	}
	bool isFull() const override {
		return count == maxSize;
	}
	void display() const {
		if (isEmpty()) {
			cout << "Empty Queue" << endl; 
		}
		else {
			for (int i = Front; i < rear; i++) {
				cout << array[i] << " ";
			}cout << endl;
		}
	}
};