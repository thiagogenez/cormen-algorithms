#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int num;
	struct Node *next;
}node;


void insert(node **head, int x){
	node *new = (node *) malloc(sizeof(node));
	new->num = x;
	new->next = *head;
	*head = new;
}

void print_list(node **head){
	node *aux;

	aux = *head;
	while(aux != NULL){
		printf("%d, ", aux->num );
		aux = aux->next;	
	}
	printf("\n");
}

void reverse(node **head, node **new_head){
	node *aux = *head;

	while(aux != NULL){
		insert(new_head,aux->num);
		aux = aux->next;
	}
}

void insert_sort(node **head, int x){
	node *new = (node *)malloc(sizeof(node));
	new->num = x;
	if(*head == NULL){
		new->next = *head;
		*head = new;		
	}
	else{
		node *aux = *head;
		node *prev = NULL;
		while(aux != NULL && aux->num < x){
			prev = aux;
			aux = aux->next;
		}
		if(prev == NULL){
			new->next = aux;
			*head = new;
		}
		else {
			prev->next = new;
			new->next = aux;
		}
	}
}

void sort(node **head, node **new_head){
	node *aux = *head;
	while(aux != NULL){
		insert_sort(new_head, aux->num);
		aux = aux->next;
	}
}

int main (void){
	node *head = NULL;
	int i = 0;

	for(i = 0; i <= 5 ; i++)
		insert(&head,i);
	for(i = -5; i < -1  ; i++)
		insert(&head,i);

	print_list(&head);
	node *new_head = NULL;
	sort(&head, &new_head);

	print_list(&new_head);
	return 0;
}

