#include "Display.h"

// relationship between the index of heap tree
int Parent(int i){
	return (i - 1)/2;
}
int Left(int i){
	return 2 * i + 1;
}
int Right(int i){
	return 2 * i + 2;
}

// maintain the maximum heap property
// pay attention to that this is just maintain
// assuming that the subtrees are all maximum heap
void MaxHeapify(int A[], int i, int heap_size){
	int l = Left(i);
	int r = Right(i);
	int largest;
	// find the maximal element in A[i] and its children
	if (l <= heap_size && A[l] > A[i]){
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= heap_size && A[r] > A[largest]){
		largest = r;
	}
	// exchange, in order to put the maximum element in position i
	if (i != largest){
		int tmp = A[i];
		A[i] = A[largest];
		A[largest] = tmp;

		// the "if statement" may destroy the maximum heap property of subtrees
		MaxHeapify(A, largest, heap_size);
	}
}

// initialize the maximum heap from the original array
void BuildMaxHeap(int A[], int length){
	int heap_size = length - 1;	
	for (int i = length/2 - 1; i >= 0; --i){
		MaxHeapify(A, i, heap_size);
	}
}

void HeapSort(int A[], int length){
	BuildMaxHeap(A, length);
	// the maximal element always in the A[0] due to the property of maximum heap
	int heap_size = length - 1;
	for (int i = length - 1; i > 0; --i){
		// exchange the A[0] and A[i]
		// A[0]: max element in maximum heap
		// A[i]: end element that hasn't been sorted
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;

		heap_size = heap_size - 1;
		MaxHeapify(A, 0, heap_size);
	}
}

int main(){
	int length;
	cout << "Please enter the number you want to enter: " << endl;
	cin >> length;
	int* A = new int[length];
	cout << "Please enter the array: " << endl;
	for (int i = 0; i < length; ++i){
		cin >> A[i];
	}

	HeapSort(A, length);
	Display(A, length);

	delete []A;
	return 0;
}
