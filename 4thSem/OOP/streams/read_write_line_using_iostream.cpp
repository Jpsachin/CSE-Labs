// http://examradar.com/getline-write-functions/

#include<bits/stdc++.h>
using namespace std;

int main() {

	char res[100];
	cout<<"ENTER WORD: ";
	cin.getline(res, 20 ,'\n');

	// cout.write(res, 40);
	// cout<<endl;

	for (int i = 1; i <= strlen(res); i++) {
		cout.write(res, i);
		cout.write("\n", 1);
	}

	return 0;
}
