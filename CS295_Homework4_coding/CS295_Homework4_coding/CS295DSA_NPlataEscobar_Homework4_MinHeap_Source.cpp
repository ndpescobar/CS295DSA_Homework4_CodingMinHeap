/*	Homework 4 Minimum Heap Implementation.
	@author: Nicolas Plata-Escobar.
	@version: vBuild 3; 1 July 2019.
*/
#include <iostream>
#include <string>

class MinHeap {
private:
	std::string *hArrPtr;
	int size;
	int capacity;
public:
	//constructors
	MinHeap(){}
	MinHeap(int inCapacity) {
		size = 0;
		capacity = inCapacity;
		hArrPtr = new std::string[inCapacity];
	}

	void AddValue(std::string inValue) {
		if (size == capacity) {
			std::cout << "Overflow: cannot add value to heap" << std::endl;
			return;
		}
		//increase size then add new value
		size++;
		hArrPtr[size - 1] = inValue;
	}

	//***(NEED TO FIX: To compare number of chars, for strings)***
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
			std::string temp = hArrPtr[index];
			hArrPtr[index] = hArrPtr[min];
			hArrPtr[min] = temp;
			Heapify(min);
		}
	}

	//This method will return and remove the root of the heap, then Heapify()
	std::string ExtractRoot() {
		//empty heap
		if (size <= 0) {
			std::cout << "Underflow: cannot extract from empty heap" << std::endl;
			return "";
		}
		//heap size of 1
		if (size == 1) {
			size--;
			return hArrPtr[0];
		}
		//temp store root, then remove it
		std::string root = hArrPtr[0];
		hArrPtr[0] = hArrPtr[size - 1];
		size--;
		Heapify(0);

		return root;
	}

	void PrintHeap(int index) {
		std::cout << "\nPrinting: ";
		for (int i = 0; i < size; i++) {
			std::cout << hArrPtr[i] << " ";
		}
		std::cout << "\nPrinting Done" << std::endl;

		//code for recursion **(does not work)**
		/*int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (index == size) { //**check this line**
			return;
		}
		if (size > 0) {
			PrintInorder(left);
			std::cout << hArrPtr[index] << std::endl;
			PrintInorder(right);
		}
		else {
			std::cout << "empty heap: nothing to print" << std::endl;
		}
		*/
	}
};

int main() {
	//testing
	MinHeap myHeap(7);
	myHeap.AddValue("This");
	myHeap.AddValue("is");
	myHeap.AddValue("my");
	myHeap.AddValue("sentence.");
	myHeap.AddValue("Now");
	myHeap.AddValue("be");
	myHeap.AddValue("coo!");
	myHeap.PrintHeap(0);
	std::cout << "Extracting the root: " << myHeap.ExtractRoot() << std::endl;
	myHeap.PrintHeap(0);
	std::cout << "Heapify!" << std::endl;
	myHeap.Heapify(0);
	myHeap.PrintHeap(0);

	//End Program
	std::cout << "Double ENTER to EXIT:";
	std::string EXIT;
	std::getline(std::cin, EXIT);
	std::getline(std::cin, EXIT);
	return 0;
}