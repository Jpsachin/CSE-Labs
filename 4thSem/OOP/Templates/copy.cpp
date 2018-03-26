#include<bits/stdc++.h>
using namespace std;

template <class T>
void copy(T a[], T b[], int n) {

	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

template <class T1, class T2>
void copy(T1 a[], T2 b[], int n) {

	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
}

int main() {

	int a[5] = {1, 2, 3, 4, 5};
	int b[10];

	copy(a, b, 5);

	cout<<"Contents of B: "<<endl;
	for (int i = 0; i < 5; i++) {
		cout<<b[i]<<endl;
	}

	char c[5] = {'1', '2', '3', '4', '5'};
	int d[10];

	copy(c, d, 5);

	cout<<"Contents of D: "<<endl;
	for (int i = 0; i < 5; i++) {
		cout<<d[i]<<endl;
	}

	return 0;
}
