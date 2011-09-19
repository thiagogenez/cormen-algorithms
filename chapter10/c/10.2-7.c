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

void print_recursive(node *head){
	node *aux = head;
	if(aux != NULL){
		print_recursive(aux->next);
		printf("%d, ",aux->num);
	}
}

void reverse_recursive(node *head, node **new_head){
	node *aux = head;
	if(aux != NULL){
		insert(new_head, aux->num);
		reverse_recursive(aux->next, new_head);
	
	}
}

void reverse(node **head, node **new_head){
	node *aux = *head;

	while(aux != NULL){
		insert(new_head,aux->num);
		aux = aux->next;
	}
}

int main (void){
	node *head = NULL;
	int i = 0;

	for(i = 0; i < 10; i++)
		insert(&head,i);

	print_list(&head);
	node *new_head = NULL;
//	reverse(&head, &new_head);	
//	print_list(&new_head);
//	printf("print_recursive: ");
//	print_recursive(head);

	reverse_recursive(head, &new_head);
	print_list(&new_head);
	printf("\n");
	return 0;
}

