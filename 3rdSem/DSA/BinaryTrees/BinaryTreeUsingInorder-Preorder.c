#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// node for binary tree
typedef struct node{
	
	struct node *left;
	struct node *right;
	int data;

} node;

char in[100];
char prp[100];

node *root = NULL;


int search(char key){
	
	int i;
	for( i = 0; i < strlen(in); i++){
		if(in[i] == key){
			return i;
		}
	}
	return -1;
}



node * create(char prp[], char in[], int ps, int pe, int ins, int ine){

		
	if(ine < ins || pe < ps){
		return NULL;
	}
	
	node * root = (node*)malloc(sizeof(node));
	root->data = prp[ps];
	
	int index = 0;
	int leftEle = 0;
	int i;
	for(i = ins; i <= ine; i++){
		
		if(in[i] == prp[ps]){
			index = i;
			break;
		}
		leftEle++;
	}
	
	root->left = create(prp, in, ps + 1, ps + leftEle , ins, index - 1);
	root->right = create(prp, in, ps + 1 + leftEle, pe, index + 1, ine);

	return root;
}

void display(node *p){

	if(p == NULL){
		return;
	}
	
	
	printf("%c->",p->data);
	printf("(");
	display(p->left);
	printf(",");
	display(p->right);
	printf(")");
	
}

void main(){
	
	int choice;
	printf("Enter inorder: ");
	gets(in);
	
	printf("Enter choice preorder(1) postorder(0): ");
	scanf("%d", &choice);
	
	printf("Enter : ");
	getchar();
	gets(prp);
	
	root = create(prp, in, 0, strlen(prp) - 1, 0, strlen(in) - 1);
	
	display(root);
	
	printf("\n\n");

}
