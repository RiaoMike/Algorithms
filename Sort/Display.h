#pragma once
#include<iostream>

using namespace std;

void Display(int A[], int length){
	cout << "the array after sort is as follows: " << endl;
	for (int i = 0; i < length; ++i){
		cout << A[i] << " ";
	}
	cout << endl;
}
