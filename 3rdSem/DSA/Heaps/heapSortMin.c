#include <stdio.h>
#include <stdlib.h>

int INT_MIN = 20000000;
int heap[1000];
int size = 0;

// function declarations
void insertNodeMinHeap(int);
void printHeap();
int parent(int i) { return (i-1)/2; }
void delete();
void heapify(int);
void decreaseKey(int, int);

void main(){
	
    int choice, data, key;

    // initialized heap
    int i;
    for(i = 0; i < 1000; i++){
    	heap[i] = INT_MIN;
    }

    x:
    printf("Enter choice:\n1.Insert\n2.Delete\n\n");
    scanf("%d", &choice);
    
    
    // choose insertion or deletion
    switch(choice){

        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertNodeMinHeap(data);
            break;

        case 2:
            delete();
            break;
          
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter pos: ");
            scanf("%d", &key);
            decreaseKey(key, data);
    }

	printHeap();
    printf("\n");
    goto x;
}

// print heap tree
void printHeap(){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ", heap[i]);
	}
}


/**
 * Insert a node in the tree 
 */
void insertNodeMinHeap(int data){

    // insert new node in leftmost position of the last unfilled level
    // as heap is a complete tree  
    heap[size] = data;
    size++;
    int i = size - 1;

    // relocate the node maintaining the heap
    // keep on swapping upwards until that node fits
    while (i != 0 && heap[parent(i)] > heap[i]) {

        int tmp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = tmp;
        i = parent(i);

    }
}


/**
 *  Arrange the tree into a heap
 */ 
void heapify(int i){

    int min;

    // locate left and right node positions
    int l = 2*i + 1;
    int r = 2*i + 2;

    // find the minimium among them 
    if (l < size && heap[i] > heap[l]){
        min = l;
    }
    else {
        min = i;
    }
    if (r < size && heap[min] > heap[r]){
        min  = r; 
    }

    // keep on swapping if either left or right is smaller
    if (min != i){
        int tmp = heap[i];
        heap[i] = heap[min];
        heap[min] = tmp;
        heapify(min);
    }
}
    

/**
 * delete the root node of the heap tree
 */     
void delete(){
    
    // check for existence of heap
    if (size > 0){
        // root node out
        printf("%d\n", heap[0]);
        heap[0] = heap[size - 1];
        heap[size - 1] = INT_MIN;
        
        // reorder heap
        size--;
        heapify(0);
    }
}


/**
 * Decrease value of a specific node 
 */ 
void decreaseKey(int i, int val){
    
    // change value
    heap[i] = val;
    
    // relocate the node maintaining the heap
    // keep on swapping upwards until that node fits
    while (i != 0 && heap[parent(i)] > heap[i]) {

        int tmp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = tmp;
        i = parent(i);

    }
}
