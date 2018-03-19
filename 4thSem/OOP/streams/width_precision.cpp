#include<bits/stdc++.h>
using namespace std;

int main() {

	for (int i = 3; i < 8; i++) {
		// set width of 	
		cout.width(10);
		// fill width with character '#'
		cout.fill('#');
		// set precision of float type output
		cout.precision(4);
		// print
		cout<<sqrt(i)<<endl;
	}


	return 0;
}
