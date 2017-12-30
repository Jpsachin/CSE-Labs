#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int data;
    struct node* next;

} node;

node **adjList;
int *visited;


int setCount = 0;
int edges = 0;

struct eWeight {
    int vertex1;
    int vertex2;
    int weight;
};

struct eWeight gWeight[1000];

int set[10000];


void createList(int);
void printList(int);
void addConnection(int, int);
void mstP(int);
void unionV(int, int, int);
void makeSet(int);
void sortWeight();
int findSet(int);


int main(){

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);
    int vertex1, vertex2;
    int repeat = 1;
    int weight;
    while (repeat){
        printf("enter vertex1: ");
        scanf("%d", &vertex1);
        printf("enter vertex2: ");
        scanf("%d", &vertex2);
        addConnection(vertex1, vertex2);
        printf("Weight: ");
        scanf("%d", &weight);
        gWeight[edges].vertex1 = vertex1;
        gWeight[edges].vertex2 = vertex2;
        gWeight[edges].weight = weight;
        edges++;
        scanf("%d", &repeat);
    }

    mstP(n);

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

void makeSet(int n){
    int i;
    for(i = 0; i < n; i++){
        set[i] = i;
        setCount++;
    }

}

void sortWeight(){

    int i, j;

    for (i = 0; i < edges - 1; i++){
        for (j = 0; j < edges - i - 1; j++){
            
            if (gWeight[j].weight > gWeight[j + 1].weight){
                int tmp = gWeight[j].weight;
                gWeight[j].weight = gWeight[j+1].weight;
                gWeight[j+1].weight = tmp;
                 tmp = gWeight[j].vertex1;
                gWeight[j].vertex1 = gWeight[j+1].vertex1;
                gWeight[j+1].vertex1 = tmp;
                 tmp = gWeight[j].vertex2;
                gWeight[j].vertex2 = gWeight[j+1].vertex2;
                gWeight[j+1].vertex2 = tmp;
            }
        }
    }
}

int findSet(int vertex){
    return set[vertex];
}

void unionV(int vertex1, int vertex2, int n){

    int tmp1 = set[vertex1];
    int tmp2 = set[vertex2];

    int i = 0;
    for (i = 0; i < n; i++){
        if (set[i] == tmp1 || set[i] == tmp2){
            set[i] = setCount;
        }
    }
    setCount++;

}


void mstP(int n){

    makeSet(n);

    sortWeight();

    int i = 0;
    for (i = 0; i < edges; i++){

        if (findSet(gWeight[i].vertex1) != findSet(gWeight[i].vertex2)){    
            
            printf("(%d, %d): %d\n", gWeight[i].vertex1, gWeight[i].vertex2, gWeight[i].weight);
            unionV(gWeight[i].vertex1, gWeight[i].vertex2, n);   

        }
    }

    
}






