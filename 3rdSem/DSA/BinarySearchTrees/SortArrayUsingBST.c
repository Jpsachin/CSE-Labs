#include<stdio.h>
#include<stdlib.h>

int arr[100];
int j = 0;

// Node of Binary Search Tree
typedef struct node {
	
	int data;
	struct node *left;
	struct node *right;
	
} node;

node* root = NULL;


// Function declarations
node* insertNodeBst(node*, int);
void displayI(node *);


void main(){

	int n;
	printf("enter size: ");
	scanf("%d", &n);
	
	// get array elements
	printf("Enter elements: \n");
	int i;
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		// insert each element into the BST
		root = insertNodeBst(root, arr[i]);
	}
	
	displayI(root);
	printf("\n");
}


/**
 *	Insert node into BST
 */
node* insertNodeBst(node* p, int data){
	
	// Create new Node
	if(p == NULL){
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	
	// go left if data is smaller
	if(p->data > data){
		p->left = insertNodeBst(p->left, data);
	}
	
	// go right if data is larger
	if(p->data < data){
		p->right = insertNodeBst(p->right, data);
	}
	
	return p;
}


/**
 * Inoder traversal of BST tree is the array sorted in ascending order
 */
void displayI(node *p){

	if(p == NULL){
		return;
	}
	
	displayI(p->left);
	printf("%d->",p->data);

	// fill array contents in ascending order
	arr[j++] = p->data;
	displayI(p->right);	
}
