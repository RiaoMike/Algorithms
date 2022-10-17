#include "Display.h"

void InsertionSort(int A[], int length){
	for (int i = 1; i < length; ++i){
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = key;
	}
}

int main(){
	// int A[] = {1, 4, 2, 9, 4, 1, 5};
	int length;
	cout << "Please enter the number you want to enter: " << endl;
	cin >> length;
	cout << "Please enter the array: " << endl;
	int* A = new int[length];
	for (int i = 0; i < length; ++i){
		cin >> A[i];
	}

	InsertionSort(A, length);
	Display(A, length);

	delete []A;
	return 0;
}
