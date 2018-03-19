#include<iostream>
using namespace std;

int main() {

	char res[100];
	int len = 0;
	char c;
	cin.get(c);
	while(c != '\n') {

		res[len++] = c;
		cin.get(c);
	}

	res[len++] = '\0';

	for (int i = 0; i < len; i++) {
		cout.put(res[i]);
	}

	cout<<endl<<"LENGTH: "<<(len)<<endl;


	return 0;
}
