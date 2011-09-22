#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	struct Node *next;
	struct Node *prev;
	int num;
	int pos;
}node;


void insert (node **head, node **tail, int value, int i){
	node *aux = malloc(sizeof(node));
	aux->num = value;
	aux->pos = i;
	aux->next = *head;
	aux->prev = NULL;
	if(*head != NULL)
		(*head)->prev = aux;
	if(*head == NULL)
		(*tail)->next = aux;
	(*head) = aux;
	(*tail)->num++;
}

void print(node **head){
	if((*head) != NULL){
		printf("%d, ",  (*head)->num);
		print(&(*head)->next);
	}
}

void get_array(int *A, char *argv[], int argc){
        int i = 0;
                for (i = 1; i < argc; i++){
                        A[i-1] = atoi(*(argv + i));
        }
}

void exchange(node *i, node *j){
        int aux = j->num;
        j->num = i->num;
        i->num = aux;
}

node* partition(node **head, node **tail){
	node *aux = *head;
	node *nodej = *head;
	node *nodei = NULL;
	node *r = *tail;
	while(aux != NULL){
		if(aux != r){
			if(aux->num <= r->num){
				nodei = aux;
				exchange(nodei, nodej);
			}
			else
				nodej = aux;
		}
			aux = aux->next;
		
	}
	if(nodei == NULL){
		exchange(*head, r);
		return (*head);
	}
	exchange(nodei->next, r);
	return (nodei->next);
}

void quick_sort(node **head, node **tail){
	if (*head != NULL && *tail != NULL && (*head)->pos < (*tail)->pos){
		node *q = partition (head,tail);
		quick_sort(head, &(q)->prev);
		quick_sort(&(q)->next, tail);
	}
}

int main(int argc, char *argv[]){
	
	int *A;

        /*allocating memory*/
        A = (int*) calloc(argc - 1, sizeof(int));

        /*array that contains unsorted number*/
        get_array(A, argv, argc);

	int i;
	node *head = NULL;
	node *tail = malloc(sizeof(node));
	tail->num = 0;

	for(i = 0; i < argc - 1; i++)	
		insert(&head, &tail, A[i], argc - 2 - i);
	
	printf("unsorted: ");	
	print(&head);
	printf("\n");

	quick_sort(&head, &(tail)->next);
	printf("sorted: ");
        print(&head);
        printf("\n");

	return 0;
}
