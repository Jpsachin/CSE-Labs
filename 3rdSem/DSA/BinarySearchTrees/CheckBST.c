#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// node of BST
typedef struct node {
	
	int data;
	struct node *left;
	struct node *right;
	
} node;

node* root = NULL;

int found = 0;
node* parent;
node* nodeKey;
int dir;

// funtion declarations
node* insertNodeBst(node*, int);
int checkBst(node*, int, int);
void printBst(node*);
node* create(int);

void main(){
	
	int choice, data;int rootEl;
	
	
	printf("Enter data at the root element: ");
	scanf("%d", &rootEl);
	root = create(rootEl);
	
	printf("Enter choice:\n1.Check\n\n");
	scanf("%d", &choice);
	
	switch(choice){
		
		case 1:
			printf("check: ");
			printf("\n%d\n", checkBst(root, INT_MIN, INT_MAX));
		
			break;
	}				
					
	printBst(root);
	printf("\n");	

}

/**
 * Create a tree
 */ 
node* create(int x){

	// -9 to denote NULL
	if(x == -9){
		
		return NULL;
	}
	
	// make new node
	node * p = (node*) malloc(sizeof(node));
	p->data = x;

	// recurse to enter for left and right children of that node
	int k;
	printf("Enter data at left of %d : enter -9 to NULL", x);
	scanf("%d", &k);
	p->left = create(k);
	printf("Enter data at right of %d : enter -9 for NULL", x);
	scanf("%d", &k);
	p->right = create(k);
	
	return p;
	
}


// print the tree
void printBst(node *p){

	if(p == NULL){
		return;
	}
	
	printf("%d->",p->data);
	printf("(");
	printBst(p->left);
	printf(",");
	printBst(p->right);
	printf(")");
	
}


/**
 * Check the each node value limiting to a range based on its parent  
 * 1 if its BST
 * 0 if its not
 */ 
int checkBst(node* p, int min, int max){

	// empty tree is BST
	if(p == NULL){
		return 1;
	}
	
	// check node and recurse for its children
	if( ((p->data > min)&&(p->data < max)) && checkBst(p->left, min, p->data) && checkBst(p->right, p->data, max) ){
			
		return 1;		
	}

	return 0;
}












