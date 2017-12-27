#include <stdio.h>
#include <stdlib.h>

// Node of AVL Tree
typedef struct node {
    struct node* left;
    struct node* right;
    int data;
    int height;
} node;

node* root = NULL;


// Function declarations
node* insertNodeAvl(node *, int);
void printAvl(node *);
int getHeight(node* );
node* createNewNode(int);
int max(int , int);
node * rightRotate(node *);
node * leftRotate(node *);
node* deleteNodeAvl(node *, int);



int main() {

    int repeat = 1, choice, data;

    while(repeat){

        // Menu
        printf("\nEnter choice \n1. Insert\n2. Delete\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insertNodeAvl(root, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                root = deleteNodeAvl(root, data);
                break;    
        }

        printAvl(root);

    
    }

    return 0;
}


/**
 * Maximum of two elements
 */
int max(int a, int b){
    return (a > b)? a : b;
}


/**
 * Get the leftmoft node in the subtree
 *
 */
node * minValueNode(node* p)
{
    node* current = p;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}


/**
 * Priting AVL tree PreOrder Traversal
 */
void printAvl(node *p){

    if(p == NULL){
        return;
    }

    printf("%d->(", p->data);
    printAvl(p->left);
    printf(",");
    printAvl(p->right);
    printf(")");

}


/**
 * Create new node
 */
node* createNewNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
}


/**
 * height of a node
 */
int getHeight(node* p){
    if(p == NULL){
        return 0;
    }
    return p->height;
}


/**
 * Check unbalance 
 */
int checkPivot(node* p){
    
    if(p == NULL){
        return 0;
    }
    int res = getHeight(p->right) - getHeight(p->left);
}


/**
 * Left Rotate
 */
node * leftRotate(node *pivot){

    // select new root node
    node* newRoot = pivot->right;

    // rotate
    pivot->right = newRoot->left;
    newRoot->left = pivot;

    // update height
    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    
    return newRoot;

}


/**
 * Right Rotate
 */
node * rightRotate(node *pivot){
    // select new root node
    node* newRoot = pivot->left;

    // rotate
    pivot->left = newRoot->right;
    newRoot->right = pivot;

    // update height
    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    
    return newRoot;

}


/**
 * Insert a node in AVL tree
 */

node* insertNodeAvl(node *p, int data){

    // BST insertion
    if(p == NULL){
        return createNewNode(data);
    }

    if(p->data > data){
        
        p->left = insertNodeAvl(p->left, data);
    }

    if(p->data < data){
       
        p->right = insertNodeAvl(p->right, data);
    }

    // update height of parent
    p->height = 1 + max(getHeight(p->right), getHeight(p->left));

    // check balance factor
    int res = checkPivot(p);

    if(res < -1){

        // LEFT LEFT case
        if(data < p->left->data){
            return rightRotate(p);
        }
        // LEFT RIGHT case
        if(data > p->left->data){
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }
    }
    if(res > 1){
        // RIGHT RIGHT case
        if(data > p->right->data){
            return leftRotate(p);
        }
        // RIGHT LEFT case
        if(data < p->right->data){
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }
    }

    return p;

}


/**
 * Delete a node in AVL tree
 */

node* deleteNodeAvl(node *p, int data){
    
    // BST deletion
    if(p == NULL){
        return NULL;
    }
    
    if(p->data > data){
            
        p->left = deleteNodeAvl(p->left, data);
    }
    
    else if(p->data < data){
           
        p->right = deleteNodeAvl(p->right, data);
    }

    else{

        if( (p->left == NULL) || (p->right == NULL) )
        { 
            node *temp = p->left ? p->left :p->right;
             if (temp == NULL)
            {
                temp = p;
                p = NULL;
            }
            else {
                *p = *temp;
            }
             
            free(temp);
        }
        else
        {
            node* temp = minValueNode(p->right);
            p->data = temp->data;
            p->right = deleteNodeAvl(p->right, temp->data);
        }
    }
    
    // check empty tree after deleting node
    if (p == NULL)
      return p;
      
    // update height   
    p->height = 1 + max(getHeight(p->right), getHeight(p->left));
    
    // check balace factor of node
    int res = checkPivot(p);
    
    if(res < -1){
        // LEFT LEFT case
        if(data < p->left->data){
            return rightRotate(p);
        }
        // LEFT RIGHT case
        if(data > p->left->data){
            p->left = leftRotate(p->left);
            return rightRotate(p);
        }    
    }
    if(res > 1){
        // RIGHT RIGHT case
        if(data > p->right->data){
            return leftRotate(p);
        }
        // RIGHT LEFT case
        if(data < p->right->data){
            p->right = rightRotate(p->right);
            return leftRotate(p);
        }
    }
    
    return p;
}   