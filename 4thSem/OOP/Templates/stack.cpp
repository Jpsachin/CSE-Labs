#include<bits/stdc++.h>
using namespace std;


template <class T>
class Stack {

	int curr;
	T *data;
	int size;

public:

	Stack(int size) {
		 this->data = new T[size];
		 this->size = size;
		 curr = -1;
	}

	void push(T ele) {
		try {
			if (curr == size - 1) {
				throw(-2);
			}
			*(data + (++curr)) = ele;
		} 
		catch (...) {
			cout<<"Stack full!"<<endl;
		}	
		
	}

	T pop() {
		try {
			if (curr == -1) {
				throw(-1);
			}
			T pop_ele = *(data + (curr--));
			return pop_ele;

		}
		catch (...){
			cout<<"Empty !"<<endl;	
		}
	}
};


int main() {

	Stack <int> s(2);
	
	s.pop(); // should be caught by try-catch

	s.push(1);
	s.push(10);

	s.push(3); // should be caught by try-catch

	for (int i = 0; i < 2; i++) {
		cout<<s.pop()<<endl;
	}


	return 0;
}
