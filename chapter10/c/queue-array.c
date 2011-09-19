#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 10

typedef struct {
	size_t head;
	size_t tail;
	size_t size;
	int items[QUEUESIZE];
}queue;


int isFull(queue *s){
	if (s->size == QUEUESIZE)
		return 1;
	return 0;
}

int isEmpty(queue *s){
	if(s->size == 0)
		return 1;
	return 0;
}

void enqueue (queue *s, int x){
	if(!isFull(s)){
		s->items[s->tail++] = x;
		s->size++;

		if(s->tail == QUEUESIZE)
			s->tail = 0;
	}else
		printf("Queue overflow!\n");
}

int dequeue (queue *s){
	if(isEmpty(s))
		printf("Queue underflow!\n");
		
	int x = s->items[s->head];
	if(s->head == QUEUESIZE)
		s->head = 0;
	else
		s->head++;
	s->size--;
	return x;
}


void print_queue(queue *s){
	int i = 0;
	printf("queue: ");
	for (i = 0; i < QUEUESIZE; i++){
		printf("%d, ",s->items[i]);
	}
	printf("\nhead: %d\n",s->head);
	printf("tail: %d\n",s->tail);
}

int main (void){
	
	queue *s;
	s = (queue *) calloc(1,sizeof(queue));

	s->head = 0;	
	s->tail = 0;
	s->size = 0;


	int i = 0;
	for(i; i < 10; i++)
		enqueue(s,i);
	print_queue(s);
	
	int a = dequeue(s);
	int b = dequeue(s);
	printf("dequeue: %d, dequeue: %d\n", a, b);
	enqueue(s,10);
	print_queue(s);
}
