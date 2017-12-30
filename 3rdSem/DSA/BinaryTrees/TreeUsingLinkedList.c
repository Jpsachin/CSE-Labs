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


void display(node *p){

	if(p == NULL){
		return;
	}
	
	printf("%d->",p->data);
	printf("(");
	display(p->left);
	printf(",");
	display(p->right);
	printf(")");
	
}

int found = 0;

void search(node *p, int key){

	if(found)
	return;
	
	if(p == NULL){
		return;
	}
	if(p->data == key){
		printf("\nFound!!\n");
		found = 1;
		return;
	}
	
	search(p->left, key);
	search(p->right, key);

}

void del(node *p){

	if(p == NULL){
		return;
	}
	
	del(p->left);
	del(p->right);
	free(p);
}


void main(){

	int rootEl;
	printf("Enter data at the root element: ");
	scanf("%d", &rootEl);
	root = create(rootEl);
	display(root);

	int key;
	printf("\nEnter element to search: ");
	scanf("%d", &key);
	found = 0;

	search(root, key);

	del(root);	

	
}







