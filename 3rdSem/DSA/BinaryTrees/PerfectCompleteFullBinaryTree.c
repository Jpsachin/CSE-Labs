#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	
	struct node *left;
	struct node *right;
	int data;

} node;

node *root = NULL;

// create tree
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

// display contents of the tree
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


// delete the tree
void del(node *p){

	if(p == NULL){
		return;
	}
	
	del(p->left);
	del(p->right);
	free(p);
}


// find if tree is full
int findFull(node *p){

	if(p->left == NULL && p->right == NULL){
		return 1;
	}
	else if( p->left != NULL && p->right == NULL){
		return 0;
	}
	else if( p->left == NULL && p->right != NULL){
		return 0;
	}
	
	return findFull(p->left)&findFull(p->right); 
	
}
int h;

// check perfect tree
int check(node *p, int level, int max){

	// this condition will be used if last level has been reached at which both right and left elements are NULL
	// now level + 1 th 
	// this implies that the condition of perfect tree is true 
	if(p == NULL){
		return 1;
	}
	
	// at a given level check whether both children are present
	if(level == max){

		// if at nodes in a level 2 children are present then true
		if(p->left != NULL && p->right != NULL){
			return 1;
		}
		// else false
		else if( p->left != NULL && p->right == NULL){
			return 0;
		}
		else if( p->left == NULL && p->right != NULL){
			return 0;
		}
		// at last level all childern shoud be NULL
		if( level == h){
			if(p->left == NULL && p->right == NULL){
				return 1;
			}
		}
		else{
		return 0;
		}	
	}
	
	else{
		// check right and left subtrees going to  next level 
		return check(p->left, level + 1, max) & check(p->right, level + 1, max);
	}
	
}



// find if tree if perfect
int findPerf(node *root){


	//int h = findHeight(root);
	printf("\nHeight of the tree is :");
	scanf("%d", &h);
	printf("%d", h);
	int hn = 1;
	// loop through all levels
	while (hn <= h){
		int res = check(root, 1,  hn);
		hn++;
		//printf("%d", res);

		// if any level is not filled then its not a perfect tree
		if(res == 0){
			return 0;
		}
	}
	
	return 1;	
}



int isComplete (node *root,unsigned int index,
                 unsigned int number_nodes)
{
    // An empty tree is complete
    if (root == NULL)
        return (1);
 
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (0);
 
    // Recur for left and right subtrees
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}

void main(){

	int rootEl;
	printf("Enter data at the root element: ");
	scanf("%d", &rootEl);
	
	// create 
	root = create(rootEl);
	
	// display tree
	display(root);

	// find category
	int k = findFull(root);
	printf("\n\n%d\n", k);
	int r = findPerf(root);
	printf("%d\n", r);
	printf("Enter no of nodes: ");
	int nn;
	scanf("%d", &nn);
	int c = isComplete(root, 0, nn);
	printf("%d\n\n", c);
	del(root);	

}







