/*	Homework 4 Minimum Heap Implementation.
	@author: Nicolas Plata-Escobar.
	@version: vBuild 2; 1 July 2019.
*/
#include <iostream>
#include <string>

class MinHeap {
private:
	int *hArrPtr;
	int size;
	int capacity;
public:
	//constructors
	MinHeap(){}
	MinHeap(int inCapacity) {
		size = 0;
		capacity = inCapacity;
		hArrPtr = new int[inCapacity];
	}

	int GetSize() {
		return size;
	}

	void InsertValue(int inValue) {
		if (size == capacity) {
			std::cout << "Overflow: cannot add value to heap" << std::endl;
			return;
		}
		//increase size then add new value
		size++;
		hArrPtr[size - 1] = inValue;
	}

	//This recursive method will traverse the heap for the given index
	void Heapify(int index) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int min = index;
		//check if left is smaller
		if (left < size && hArrPtr[left] < hArrPtr[index]) {
			min = left;
		}
		//check if right is smaller
		if (right < size && hArrPtr[right] < hArrPtr[min]) {
			min = right;
		}
		//check next pair, if index is not there
		if (min != index) {
			Swap(&hArrPtr[index], &hArrPtr[min]);
			Heapify(min);
		}
	}

	int ExtractRoot() {
		//empty heap
		if (size <= 0) {
			std::cout << "Underflow: cannot extract from empty heap" << std::endl;
			return -1;
		}
		//heap size of 1
		if (size == 1) {
			size--;
			return hArrPtr[0];
		}
		//temp store root, then remove it
		int root = hArrPtr[0];
		hArrPtr[0] = hArrPtr[size - 1];
		size--;
		Heapify(0);

		return root;
	}

	void Swap(int *x, int *y) {
		int temp = *x;
		*x = *y;
		*y = temp;
	}
};

int main() {

	std::cout << "Double ENTER to EXIT:";
	std::string EXIT;
	std::getline(std::cin, EXIT);
	std::getline(std::cin, EXIT);
	return 0;
}