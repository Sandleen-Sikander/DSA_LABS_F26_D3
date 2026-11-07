#pragma once
#include<iostream>
#include "List.h"
using namespace std;
template <class Type>
class MyList : public List<Type> {
public:
	//PARAMETERIZED CONSTRUCTOR
	MyList(int size = 8) : List<Type>(size) {}
	//COPY-CONSTRUCTOR
	MyList(const MyList<Type>& obj) : List<Type>(obj) {}

	void addElementAtFirstIndex(Type value) override {
		if (this->currentSize == this->maxSize) {
			cout << "List is Full !!!" << endl;
			return;
		}
		for (int i = this->currentSize; i > 0; i--) {
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[0] = value;
		this->currentSize++;
	}
	void addElementAtLastIndex(Type value) override {
		if (this->currentSize == this->maxSize) {
			cout << "List is Full !!!" << endl;
			return;
		}
		this->arr[this->currentSize] = value;
		this->currentSize++;
	}
	Type removeElementFromEnd() override {
		if (this->currentSize == 0) {
			cout << "My List is Empty." << endl;
			return Type();
		}
		Type value = this->arr[this->currentSize - 1];
		this->currentSize--;
		return value;
	}
	void removeElementFromStart() override {
		if (this->currentSize == 0) {
			cout << "My List is Empty." << endl;
			return;
		}
		for (int i = 0; i < this->currentSize - 1; i++) {
			this->arr[i] = this->arr[i + 1];
		}
		this->currentSize--;
	}
	bool empty() {
		return this->currentSize == 0;
	}
	bool full() {
		return this->currentSize == this->maxSize;
	}
	int size() {
		return this->currentSize;
	}
	bool insertAt(int index, Type value) {
		if (index < 0 || index > this->currentSize || this->currentSize == this->maxSize) {
			return false;
		}
		for (int i = this->currentSize; i > index; i--) {
			this->arr[i] = this->arr[i - 1];
		}
		this->arr[index] = value;
		this->currentSize++;
		return true;
	}
	Type last() {
		if (this->currentSize == 0) {
			cout << "List is empty." << endl;
			return Type();
		}
		return this->arr[this->currentSize - 1];
	}
	bool search(Type value) {
		for (int i = 0; i < this->currentSize; i++) {
			if (this->arr[i] == value) {
				return true;
			}
		}
		return false;
	}
	void display()
	{
		if (this->currentSize == 0) {
			cout << "List is empty." << endl;
			return;
		}
		for (int i = 0; i < this->currentSize; i++) {
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
	~MyList() override {}
};

