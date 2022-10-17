#include "Display.h"

// input array: A
// output array: B
// n: the length of A and B
// the entries of A is range from 0 to k
void CountingSort(int A[], int B[], int n){
	// compute the k, which is the maximal element of A
	int k = A[0];
	for (int i = 1; i < n; ++i){
		if (A[i] > k){
			k = A[i];
		}
	}
	// range from 0 to k **containing k**
	k = k + 1;
	int *C = new int[k];
	// initialize
	for (int i = 0; i < k; ++i){
		C[i] = 0;
	}
	// C[i] contains the number of i 
	for (int i = 0; i < n; ++i){
		C[A[i]]	= C[A[i]] + 1;
	}
	// C[i] contains the number of elements less than or equal to i
	for (int i = 1; i < k; ++i){
		C[i] = C[i] + C[i-1];
	}

	for (int j = 0; j < n; ++j){
		B[C[A[j]] - 1] = A[j];
		C[A[j]] = C[A[j]] - 1;
	}

	delete [] C;
}

int main(){
	// testing
	// int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
	// int length = sizeof(A)/sizeof(A[0]);
	// int *B = new int[length];
	int length;
	cout << "Please enter the number you want to enter: " << endl;
	cin >> length;
	int* A = new int[length];
	int* B = new int[length];
	cout << "Please enter the array: " << endl;
	for (int i = 0; i < length; ++i){
		cin >> A[i];
	}

	CountingSort(A, B, length);
	
	Display(B, length);
	
	delete []A;
	delete []B;
	return 0;
}
