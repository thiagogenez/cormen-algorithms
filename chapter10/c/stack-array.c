#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10

typedef struct {
	size_t size;
	int items[STACKSIZE];
}stack;


int isFull(stack *s){
	if (s->size == 10)
		return 1;
	return 0;
}

int isEmpty(stack *s){
	if(s->size == 0)
		return 1;
	return 0;
}

void push (stack *s, int x){
	if(!isFull(s)){
		s->items[s->size++] = x;
	}else{
		printf("Stack overflow!\n");
		exit(1);
	}
}

int pop (stack *s){
	if(isEmpty(s)){
		printf("Stack underflow!\n");
		exit(1);
	}
	int x = s->items[--s->size];
	return x;
}


void print_stack(stack *s){
	int i = 0;
	printf("stack: ");
	for (i = 0; i < s->size; i++){
		printf("%d, ",s->items[i]);
	}
	printf("\nsize: %d\n",s->size);
}

int main (void){
	
	stack *s;
	s = (stack *) calloc(1,sizeof(stack));
	s->size = 0;	
	
	int i = 0;
	for(i; i < 10; i++)
		push(s,i);
	print_stack(s);
	
	int a = pop(s);
	int b = pop(s);
	printf("pop: %d, pop: %d\n", a, b);
	print_stack(s);
}
