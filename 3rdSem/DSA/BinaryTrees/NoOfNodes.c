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
	printf("Enter data at left of %d : enter -9 to NULL: ", x);
	scanf("%d", &k);
	p->left = create(k);
	printf("Enter data at right of %d : enter -9 for NULL: ", x);
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

int count = 0;
void noOfNodes(node *p){
	
	if(p == NULL){
		return;
	}
	
	noOfNodes(p->left);
	noOfNodes(p->right);
	count++;
}


void main(){

	int rootEl;
	printf("Enter data at the root element: ");
	scanf("%d", &rootEl);
	root = create(rootEl);
	display(root);

	noOfNodes(root);
	printf("\nNo of nodes : %d", count);

	
}







