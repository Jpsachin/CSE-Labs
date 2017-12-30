#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	struct node *left;
	struct node *right;
	int data;

} node;

node *root = NULL;


node* create(int x){

	if(x == -9){
		
		return NULL;
	}
	
	node * p = (node*) malloc(sizeof(node));
	p->data = x;

	int k;
	printf("Enter data at left of %d : enter -9 to NULL", x);
	scanf("%d", &k);
	p->left = create(k);
	printf("Enter data at right of %d : enter -9 for NULL", x);
	scanf("%d", &k);
	p->right = create(k);
	
	return p;
	
}


void displayPr(node *p){

	if(p == NULL){
		return;
	}
	
	printf("%d->",p->data);
	displayPr(p->left);
	displayPr(p->right);

	
}

void displayI(node *p){

	if(p == NULL){
		return;
	}
	displayI(p->left);
	printf("%d->",p->data);
	displayI(p->right);

	
}

void displayPo(node *p){

	if(p == NULL){
		return;
	}
	

	displayPo(p->left);

	displayPo(p->right);
		printf("%d->",p->data);
	
}



void main(){

	int rootEl;
	printf("Enter data at the root element: ");
	scanf("%d", &rootEl);
	root = create(rootEl);
	displayPr(root);
	printf("\n");
	displayI(root);
	printf("\n");
	displayPo(root);
	printf("\n");



	

	
}







