#pragma once
#include<iostream>
#include "MyList.h"
using namespace std;
template <class Type>
class CustomList : public MyList<Type> {
public:
    //PARAMETERIZED CONSTRUCTOR
    CustomList(int capacity = 8) : MyList<Type>(capacity) {}
    //COPY-CONSTRUCTOR
    CustomList(const CustomList<Type>& other) : MyList<Type>(other) {}
    Type sum_ofPrime() {
        Type sum = 0;
        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];
            if (value < 2)
                continue;
            bool prime = true;
            for (int j = 2; j <= value / j; j++) {
                if (value % j == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime)
                sum = sum + value;
        }
        return sum;
    }
    Type secondMaxEven() {
        Type largest = 0;
        Type second = 0;

        bool foundLargest = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];
            if (value % 2 != 0)
                continue;

            if (!foundLargest || value > largest) {
                if (foundLargest && value != largest) {
                    second = largest;
                    foundSecond = true;
                }
                largest = value;
                foundLargest = true;
            }
            else if (value < largest && (!foundSecond || value > second)) {
                second = value;
                foundSecond = true;
            }
        }
        if (!foundSecond) {
            cout << "Second maximum even number does not exist." << endl;
            return Type();
        }
        return second;
    }
    Type secondMinOdd() {
        Type smallest = 0;
        Type second = 0;

        bool foundSmallest = false;
        bool foundSecond = false;

        for (int i = 0; i < this->currentSize; i++) {
            Type value = this->arr[i];

            if (value % 2 == 0)
                continue;

            if (!foundSmallest || value < smallest) {
                if (foundSmallest && value != smallest) {
                    second = smallest;
                    foundSecond = true;
                }
                smallest = value;
                foundSmallest = true;
            }
            else if (value > smallest && (!foundSecond || value < second)) {
                second = value;
                foundSecond = true;
            }
        }
        if (!foundSecond)
        {
            cout << "Second minimum odd number does not exist." << endl;
            return Type();
        }
        return second;
    }
    void printDuplicates() {
        bool anyDuplicate = false;

        for (int i = 0; i < this->currentSize; i++) {
            bool appearedBefore = false;
            for (int j = 0; j < i; j++) {
                if (this->arr[i] == this->arr[j]) {
                    appearedBefore = true;
                    break;
                }
            }
            if (appearedBefore)
                continue;

            int count = 0;
            for (int j = 0; j < this->currentSize; j++) {
                if (this->arr[i] == this->arr[j])
                    count++;
            }
            if (count > 1) {
                cout << this->arr[i] << " ";
                anyDuplicate = true;
            }
        }
        if (!anyDuplicate)
            cout << "No duplicates found.";

        cout << endl;
    }
    void rotateClockwaise(int r) {
        int firstHalf = this->currentSize / 2;
        int secondHalf = this->currentSize - firstHalf;

        // Rotate first half clockwise
        for (int step = 0; step < r; step++) {
            if (firstHalf > 1) {
                Type temp = this->arr[firstHalf - 1];
                for (int j = firstHalf - 1; j > 0; j--) {
                    this->arr[j] = this->arr[j - 1];
                }
                this->arr[0] = temp;
            }
        }

        // Rotate second half clockwise
        for (int step = 0; step < r; step++) {
            if (secondHalf > 1) {
                Type temp = this->arr[this->currentSize - 1];
                for (int j = this->currentSize - 1; j > firstHalf; j--) {
                    this->arr[j] = this->arr[j - 1];
                }
                this->arr[firstHalf] = temp;
            }
        }
    }
    void rotateanitclockwaise(int rt)
    {
        int firstHalf = this->currentSize / 2;
        int secondHalf = this->currentSize - firstHalf;
        // Rotate first half anti-clockwise
        for (int step = 0; step < rt; step++) {
            if (firstHalf > 1) {
                Type temp = this->arr[0];
                for (int j = 0; j < firstHalf - 1; j++) {
                    this->arr[j] = this->arr[j + 1];
                }
                this->arr[firstHalf - 1] = temp;
            }
        }
        // Rotate second half anti-clockwise
        for (int step = 0; step < rt; step++) {
            if (secondHalf > 1) {
                Type temp = this->arr[firstHalf];
                for (int j = firstHalf; j < this->currentSize - 1; j++) {
                    this->arr[j] = this->arr[j + 1];
                }
                this->arr[this->currentSize - 1] = temp;
            }
        }
    }
    ~CustomList() override {}
};

