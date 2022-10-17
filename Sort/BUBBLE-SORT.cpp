#include "Display.h"

void BubbleSort(int A[], int length){
	int tmp;
	for (int i = 0; i < length - 1; ++i){
		for (int j = length - 1; j > i; --j){
			if (A[j] < A[j-1]){
				tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
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

	BubbleSort(A, length);
	Display(A, length);

	delete []A;
	return 0;
}
