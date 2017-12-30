#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

} node;

node **adjList;

void createList(int);
void printList(int);
void addConnection(int, int);

int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);
    int vertex1, vertex2;
    int repeat;
    while (repeat){
        printf("enter vertex1: ");
        scanf("%d", &vertex1);
        printf("enter vertex2: ");
        scanf("%d", &vertex2);
        addConnection(vertex1, vertex2);
        scanf("%d", &repeat);
    }

    printList(n);
    printf("\n");
    return 0;
}

void createList(int n){
    adjList = (node **)malloc(sizeof(node *)*n);
    int i;
    for(i = 0; i < n; i++){
    	adjList[i] = NULL;
    }
}

void printList(int n){
	int i = 0;
	for(i = 0; i < n; i++){
		node *tmp = adjList[i];
		printf("%d = ", i);
		while(tmp != NULL){
			
			printf("%d -> ", tmp->data);
			tmp = tmp->next;
		}
		if(tmp == NULL){
			printf("->NULL");
		}
		printf("\n");
	}    
}

void addConnection(int vertex1, int vertex2){
	
	node *newNode1 = (node*)malloc(sizeof(node));
	newNode1->data = vertex1;
	node *newNode2 = (node*)malloc(sizeof(node));
	newNode2->data = vertex2;
	
	newNode2->next = adjList[vertex1];
	adjList[vertex1] = newNode2;
	 
	newNode1->next = adjList[vertex2];
	adjList[vertex2] = newNode1;   
}


