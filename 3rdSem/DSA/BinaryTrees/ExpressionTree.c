#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	
	struct node *left;
	struct node *right;
	char data;

} node;

char a[100];
node * stack[100];
char stack1[1000];
int top = -1;
int top1 = -1;
int ctop = 0;


char pop1(){
	
	char tmp = stack1[top1];
	top1--;
	return tmp;	
	
}

void push1(char c){
	top1++;
	stack1[top1] = c;
}



node * pop(){
	
	if(top == -1){
		return NULL;
	}
	node *tmp = stack[top];
	top--;
	return tmp;
}

void push(node * k){
	
	top++;
	stack[top] = k;
} 

node *root = NULL;

int isOp(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '(' || c == ')')
        return 1;
    return 0;
}


int pre(char c){

	switch(c){
	
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '(':
			return -1;
						
	}
}

node* newNode(char c){
    node *temp = (node*) malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;    
    temp->data = c;
    return temp;
}

void create(char b[], int n){
	
	int i;
	for (i = 0; i < n; i++){
		
		if(isOp(b[i])){
			
			node *newNod = newNode(b[i]);
			node * b = pop();
			node * a = pop();
			newNod->left = a;
			newNod->right = b;
			push(newNod);	
		}
		else{
			node *newNod = newNode(b[i]);
			push(newNod);			
		}
		
		
	}
	
	root = stack[0];
	
}

void displayI(node *p){

	if(p == NULL){
		return;
	}
	
	printf("%c ",p->data);
	displayI(p->left);
	
	displayI(p->right);

	
}

void main(){

		
	char s[100];
	printf("Enter postfix expression: ");
	gets(s);
	int len = strlen(s);
	
	// 
	int i;
	for(i = 0; i < strlen(s); i++){
		
		//printf("%c\n", s[i]);
		if(isOp(s[i]) == 1){
			
			if(s[i] == ')'){
				//printf(")discovered\n");
				char tmp = pop1();
				while(tmp != '('){
					a[ctop] = tmp;
					ctop++;
					tmp = pop1();
				}
				
				
			}
			else if (s[i] == '('){
				//printf("(discovered\n");
				push1(s[i]);
			}
			else{
				//printf("OPdiscovered\n");
				while(pre(stack1[top1]) >= pre(s[i]) && top1 >= 0){
				
					a[ctop] = pop1();
					ctop++;
				}
				push1(s[i]);
			}
		}
		else{
			
			a[ctop] = s[i];
			ctop++;
		}
		
	}
	
	char tmp2;
	while(top1 >= 0 && tmp2 != '('){
		tmp2 = pop1();
		a[ctop] = tmp2;
		ctop++;
	}
	
	a[ctop] = '\0';	
	
	
	int len1 = strlen(a);
	create(a, len1);
	displayI(root);
	printf("\n");
}

