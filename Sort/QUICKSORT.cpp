#include "Display.h"

int Partition(int A[], int p, int q){
	int key = A[q];
	int i = p - 1;
	for (int j = p; j < q; ++j){
		if (A[j] <= key){
			i++;
			int tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	int tmp = A[q];
	A[q] = A[i+1];
	A[i+1] = tmp;
	return i + 1;
}

void QuickSort(int A[], int p, int q){
	if (p < q){
		int r = Partition(A, p, q);
		QuickSort(A, p, r-1);
		QuickSort(A, r+1, q);
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

	QuickSort(A, 0, length-1);
	Display(A, length);

	delete[] A;
	return 0;
}
