#include<stdio.h>
#include<stdlib.h>

typedef struct nodeP {

	int data;
	int pri;
	struct nodeP * next;

} nodeP;
nodeP* head = NULL;

int eWeight[1000][1000];

void enq(int, int);
nodeP* deq();
void print();

typedef struct node{

    int data;
    struct node* next;

} node;

node **adjList;
int *visited;

void createList(int);
void printList(int);
void addConnection(int, int);
void mstK(int);


int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);
    int vertex1, vertex2;
    int weight;
    int repeat;
    while (repeat){
        printf("enter vertex1: ");
        scanf("%d", &vertex1);
        printf("enter vertex2: ");
        scanf("%d", &vertex2);
        addConnection(vertex1, vertex2);
        printf("Weight: ");
        scanf("%d", &weight);
        eWeight[vertex1][vertex2] = weight;
        eWeight[vertex2][vertex1] = weight;
        scanf("%d", &repeat);
    }
	printList(n);
	mstK(n);
    
    printf("\n");
    return 0;
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
	
	node *newNode1 = (node*)malloc(sizeof(node));
	newNode1->data = vertex1;
	
	newNode1->next = adjList[vertex2];
	adjList[vertex2] = newNode1;
	    
}

void mstK(int n){
	
	enq(0, 0);
	nodeP *i;
	while(head != NULL){
	
		i = deq();
		if (visited[i->data] == 1){
			continue;
		}
		
		visited[i->data] = 1;
		printf("%d %d\n", i->data, i->pri);
		
		node *tmp = adjList[i->data];
		while(tmp != NULL){
			enq(tmp->data, eWeight[i->data][tmp->data]);
			tmp = tmp->next;
		}

	}
}

void print(){

	printf("HEAD ->");
	
	nodeP *ptr = head;
	
	while(ptr != NULL){
		printf("(%d, %d) ->", ptr->pri, ptr->data);
		ptr = ptr->next;
	}
	
	printf("NULL\n");
}

void enq(int data, int pri){

	nodeP *newNode = (nodeP *)malloc(sizeof(nodeP));
	newNode->data = data;
	newNode->pri = pri;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;

		return;
	}
	else if (head->pri > newNode->pri){
		newNode->next = head;
		head = newNode;

		return;
	}
	
	nodeP* ptr = head;
	
	while (ptr->next != NULL){
	
		if(ptr->next->pri > newNode->pri){
			newNode->next = ptr->next;
			ptr->next = newNode;

			return;
		}
		ptr = ptr->next;
	}
	
	ptr->next = newNode;
	

}

nodeP* deq(){

	if(head == NULL){
	
		printf("Empty!\n");
		return NULL;
	}
	
	int temp = head->data;
	nodeP *tmp = head;
	head = head->next;
	
	return tmp;
}









