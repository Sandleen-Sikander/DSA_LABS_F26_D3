#include <iostream>
#include <string>
using namespace std;
 
template <typename T>
int binarySearch(T arr[], T value, int size) {
    int low = 0;
    int high = size - 1; 
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    } 
    return -1;
} 

template <typename T>
void printSearchResult(int index, T value) {
    if (index != -1) {
        cout << value << " found at index " << index << endl;
    }
    else {
        cout << value << " not found in the array" << endl;
    }
}
//Binary search requires a sorted array.
int main() {
    // Test with an integer array (sorted) of size 5
    int intArray[5] = { 11, 22, 23, 25, 64 };
    int intKey = 22;

    int intIndex = binarySearch(intArray, intKey, 5);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted) of size 4
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;

    int floatIndex = binarySearch(floatArray, floatKey, 4);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";

    int stringIndex = binarySearch(stringArray, stringKey, 4);
    printSearchResult(stringIndex, stringKey);

    return 0;
}
