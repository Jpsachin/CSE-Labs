#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000

int a[SIZE];
int height;

void delete(int i){

	if(i > SIZE - 1){
		return;
	}
	
	delete(2*i + 1);
	delete(2*i + 2);
	a[i] = 0;
	
}



void main(){
	

	
	printf("Enter root element: ");
	scanf("%d", &a[0]);
	
	int i, l, r;
	int h = 1;
	
	// enter elements
	for (i = 0; h ; i++){
	
		printf("Enter left node: for %d: ", a[i]);
		scanf("%d", &l);
		a[2*i + 1] = l;
		printf("Enter right node: for %d: ", a[i]);
		scanf("%d", &r);
		a[2*i + 2] = r;
		printf("Enter 0 to exit: ");
		scanf("%d", &h);
		height++;
		
	}
	
	// search
	int key;
	printf("Enter key to search: ");
	scanf("%d", &key);
	int found = 0;
	for(i = 0; i < SIZE; i++){
		
		if(key == a[i]){
			found = 1;
			break;
		}		
	}
	
	if (found){
		printf("Found!!\n");
	}
	else{
		printf("Not found!!\n");
	}


	// print
	for(i = 0; i < height; i++){
		
		printf("%d -> (%d, %d)\n", a[i], a[2*i + 1], a[2*i + 2]);
	}

	
	// delete
	int del;
	printf("Enter node ele to delete: ");
	scanf("%d", &del);

	for(i = 0; i < SIZE; i++){
		
		if(del == a[i]){
			found = 1;
			break;
		}		
	}
	
	if (found){
		delete(i);
		
	}
	else{
		printf("Not found!!\n");
	}
	
	// print
	for(i = 0; i < height; i++){
		
		printf("%d -> (%d, %d)\n", a[i], a[2*i + 1], a[2*i + 2]);
	}


}
