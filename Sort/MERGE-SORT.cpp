#include "Display.h"

void Merge(int A[], int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	// L and R represent for the left and right area of A[p, r]
	// assume that L and R have already been sorted
	int* L = new int[n1];
	int* R = new int[n2];
	// initialized
	for (int i = 0; i < n1; ++i){
		L[i] = A[i + p];
	}
	for (int j = 0; j < n2; ++j){
		R[j] = A[j + q + 1];
	}
	int a = 0, b = 0; // a, b showing where you are now in each array
	int pos = p; // showing where you are now in A
	// ordering the A of index from p to r
	while (a != n1 && b != n2){
		if (L[a] < R[b]){
			A[pos] = L[a];
			a = a + 1; // position of L move backward
		}
		else {
			A[pos] = R[b];
			b = b + 1; // position of R move backward
		}
		pos = pos + 1; // position of A move backward anyway
	}
	while (a < n1){
		A[pos] = L[a];
		pos = pos + 1;
		a = a + 1;
	}
	while (b < n2){
		A[pos] = R[b];
		pos = pos + 1;
		b = b + 1;
	}
	// note that the two "while" will happen only one
}
// sort array A range from index p to index r(containing p and r)
void MergeSort(int A[], int p, int r){
	if(p < r) {
		int q = (p + r)/2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
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

	MergeSort(A, 0, length-1);
	Display(A, length);

	delete []A;
	return 0;
}
