#include <iostream>
#include <string>
using namespace std;
 
template <typename T>
int linearSearch(T arr[], T value, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
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

int main() {
    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intKey = 12;

    int intIndex = linearSearch(intArray, intKey, 5);
    printSearchResult(intIndex, intKey);

    // Test with a float array of size 4
    float floatArray[4] = { 3.14, 1.62 , 2.71, 0.57 };
    float floatKey = 1.62;

    int floatIndex = linearSearch(floatArray, floatKey, 4);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array of size 4
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";

    int stringIndex = linearSearch(stringArray, stringKey, 4);
    printSearchResult(stringIndex, stringKey);

    return 0;
}