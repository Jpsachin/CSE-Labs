#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

} node;

node **adjList;
int *visited;

int q[1000];
int front = -1;
int back = -1;

void createList(int);
void printList(int);
void addConnection(int, int);
void bfs(int);
void enqueue(int);
int dequeue();

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
	bfs(n);
    
    printf("\n");
    return 0;
}

void enqueue(int p){
	
	if(front == -1){
		front = 0;
		back = 0;
		q[back] = p;
	}
	else{
		back++;
		q[back] = p;
	}
}

int dequeue(){

	if(front == -1){
		return -1;
	}
	
	if(front == back){
		int tmp = q[front];
		front = -1;
		back = -1;
		return tmp;
	}
	else{
		int tmp = q[front];
		front++;
		return tmp;
	}
}

void createList(int n){
    adjList = (node **)malloc(sizeof(node *)*n);
    int i;
    for(i = 0; i < n; i++){
    	adjList[i] = NULL;
    }
    visited = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
    	visited[i] = 0;
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

	node *newNode2 = (node*)malloc(sizeof(node));
	newNode2->data = vertex2;
	
	newNode2->next = adjList[vertex1];
	adjList[vertex1] = newNode2;
	    
}

void bfs(int n){
	
	enqueue(0);
	
	while(front != -1){
	
		int p = dequeue();
		visited[p] = 1;
		printf("%d ", p);
		
		node *tmp = adjList[p];
		while(tmp != NULL){
			if(visited[tmp->data] != 1){
				enqueue(tmp->data);
			}
			tmp = tmp->next;
		}
	}
}









