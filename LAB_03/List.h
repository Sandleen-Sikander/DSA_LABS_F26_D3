#pragma once
template <class Type>
class List {
protected:
	Type* arr;
	int maxSize;
	int currentSize;
public:
	//PARAMETERIZED CONSTRUCTOR
	List(int size = 8) {
		maxSize = size;
		currentSize = 0;
		arr = new Type[maxSize];
	}
	//COPY-CONSTRUCTOR
	List(const List<Type>& another) {
		maxSize = another.maxSize;
		currentSize = another.currentSize;
		arr = new Type[maxSize];
		for (int i = 0; i < currentSize; i++) {
			arr[i] = another.arr[i];
		}
	}
	//PURE VIRTUAL FUNCTIONS
	virtual void addElementAtFirstIndex(Type) = 0;
	virtual void addElementAtLastIndex(Type) = 0;
	virtual Type removeElementFromEnd() = 0;
	virtual void removeElementFromStart() = 0;
	//DEFAULT CONSTRUCTOR
	virtual ~List() {
		delete[] arr;
	}
};

