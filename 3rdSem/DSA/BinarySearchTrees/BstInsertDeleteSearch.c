#include <stdio.h>
#include <stdlib.h>

// node for a BST
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

// function declarations
void searchBst(node*, int);
node* insertNodeBst(node*, int);
void deleteNodeBst(node*, int);
void printBst(node*);

void main(){

    int choice, data;
    x:
    printf("Enter choice:\n1.Insert\n2.Delete\n3.Search\n\n");
    scanf("%d", &choice);

    // choice to INSERT, DELETE, SEARCH a BST
    switch(choice){

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            root = insertNodeBst(root, data);
            break;
        case 2:
            printf("Enter data to be deleted: ");
            scanf("%d", &data);
            deleteNodeBst(root, data);
            break;
        case 3:
            printf("Enter data to be found: ");
            scanf("%d", &data);
            found = 0;
            searchBst(root, data);
            if(found){
                printf("\nFound\n");
            }
            else{
                printf("\nNot Found\n");
            }
            break;

    }
    printBst(root);
    printf("\n");
    goto x;

}


/**
 * Print BST 
 */ 
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
 * Insert a node into BST
 */ 
node* insertNodeBst(node* p, int data){

    // create new node
    if(p == NULL){
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // go to left if data is smaller
    if(p->data > data){
        p->left = insertNodeBst(p->left, data);
    }

    // go to right if data is greater
    if(p->data < data){
        p->right = insertNodeBst(p->right, data);
    }

    return p;
}


/**
 * Delete a node from BST 
 */ 
void deleteNodeBst(node* p, int key){

    // search the BST for the node 
    searchBst(root, key);

    // if only left child exists for that node
    // attach left child to the parent
    node* ptr = nodeKey->right;
    if(ptr == NULL){
        if(dir){
            parent->right = nodeKey->left;
        }
        else{
            parent->left = nodeKey->left;
        }
        free(nodeKey);
        return;
    }

    
    // find left most node of right subtree of the node
    while(ptr->left != NULL){
        ptr = ptr->left;
    }

    // move the node's left subtree to leftmost node of the right subtree of node
    ptr->left = nodeKey->left;

    // move node's right subtree to its parent in the correct direction
    if(dir){
        parent->right = nodeKey->right;
    }
    else{
        parent->left = nodeKey->right;
    }

    free(nodeKey);

}

// node* deleteNodeBst(node* p, int data){

//     if(p == NULL){
//         return  NULL;
//     }

//     if(p->data > data){
//         p->left = deleteNodeBst(p->left, data);
//     }

//     else if (p->data < data){
//         p->right = deleteNodeBst(p->right, data);
//     }


//     else {
        
//         // Alternate logic to delete a node from a BST

//         // if (p->left == NULL && p->right == NULL){
//         //     free(p);
//         //     return NULL;
//         // }
//         // else if (p->left == NULL && p->right  != NULL){
            
//         //     p->data = p->right->data;
            
//         //     free(p->right);
//         //     p->right  = NULL;
//         //     return p;
//         // }
//         // else if (p->left != NULL && p->right  == NULL){
//         //     p->data = p->left->data;
            
//         //     free(p->left);
//         //     p->left  = NULL;
//         //     return p;
//         // }
        
//         // Check if 0, 1 children
//         if (p->left == NULL)
//         {
//              node *temp = p->right;
//             free(p);
//             return temp;
//         }
//         else if (root->right == NULL)
//         {
//              node *temp = p->left;
//             free(p);
//             return temp;
//         }
 
//         // 2 children 
//         // Replace with 
//         node *tmp = findMinValue(p->right);
//         p->data = tmp->data;
//         p->right = deleteNodeBst(p->right, p->data);
        
//     }

//     return p;

// }


/**
 * Search a BST 
 * Also sets parent and direction of child left
 */ 
void searchBst(node* p, int key){

    // check if root has key
    if(root->data == key){
        parent = NULL;
        dir = 1;
        nodeKey = root;
        found = 1;
        return;
    }

    if(p != NULL){

        // check right node key
        if(p->right != NULL){

            if(p->right->data == key){
                found = 1;
                parent = p;
                dir = 1;
                nodeKey = p->right;
                return;
            }
        }

        // check left node key
        if(p->left != NULL){

            if(p->right->data == key){
                found = 1;
                parent = p;
                dir = 0;
                nodeKey = p->left;
                return;
            }
        }

        // check child of left node key
        if(p->left != NULL){

            if(p->left->data > key){
                searchBst(p->left, key);
            }

        }

        // check child of right node key
        if(p->right != NULL){

            if(p->right->data < key){
                searchBst(p->right, key);
            }
        }

    }

}   


// int searchBst (node *p, int data){

//     if(p == NULL){
//         return 0;
//     }
//     if(p->data = key){
//         return true;
//     }
//     if(p->data > data){
//         return searchBst(p->left, data);
//     }
//     if(p->data < data){
//         return searchBst(p->right, data);
//     }
// }










