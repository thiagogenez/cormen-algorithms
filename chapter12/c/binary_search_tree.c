#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	struct Node *l;
	struct Node *r;
	struct Node *p;
	int num;
}node;

void get_array(int *A, char *argv[], int argc){
        int i = 0;
                for (i = 1; i < argc; i++){
                        A[i-1] = atoi(*(argv + i));
        }
}




void insert(node **root, int x){
	if(*root == NULL){
		(*root) = malloc(sizeof(node));
        	(*root)->l = NULL;
	        (*root)->r = NULL;
        	(*root)->num = x;
	}
	else{
		if((*root)->num < x)
			insert(&(*root)->r,x);
		else
			insert(&(*root)->l,x);
	}
}

void print_inorder(node **root){
	if(*root != NULL){
		print_inorder(&(*root)->l);
		printf("%d, ", (*root)->num);
		print_inorder(&(*root)->r);
	}
}

int get_minimum(node **root){
	if((*root)->l != NULL)
		return get_minimum(&(*root)->l);
	return (*root)->num;
}

int get_maximum(node **root){
	if((*root)->r != NULL)
		return get_maximum(&(*root)->r);
	return (*root)->num;
}

int counting_nodes(node **root){
	if((*root) == NULL)
		return 0;
	return 1 + counting_nodes(&(*root)->l) + counting_nodes(&(*root)->r);
}

int counting_leaves(node **root){
	if((*root) == NULL)
	        return 0;
	if((*root)->l == NULL && (*root)->r == NULL)
		return 1;
	return 0 + counting_leaves(&(*root)->l) + counting_leaves(&(*root)->r);
}	

int bigger(int a, int b){
	if (a > b)
		return a;
	return b;
}

int get_depth(node **root){
	if((*root) == NULL || ((*root)->l == NULL && (*root)->r == NULL))
		return 0;
	return (1 + bigger(get_depth(&(*root)->l), get_depth(&(*root)->r)));
}

void enqueue(node **head, node *real){
	if((*head) == NULL){
		(*head) = malloc(sizeof(node));
		(*head)->num = 0;
		(*head)->l = NULL;
		(*head)->r = real;
	}
	else
		enqueue(&(*head)->l,real);
}
node* dequeue(node **head){
	if((*head) != NULL){
		node *aux = *head;
		*head = (*head)->l;
		return aux;
	}
	return (*head);
}
void print_level(node **root){
	node *head = NULL;
	if((*root) != NULL){
		enqueue(&head, (*root));
		while(head != NULL){
			node *aux = dequeue(&head)->r;
			printf("%d, ", aux->num);
			if(aux->l != NULL)
				enqueue(&head, aux->l);
			if(aux->r != NULL)
			        enqueue(&head, aux->r);
		}
	}
}
void print_queue(node **head){
	if(*(head) != NULL){
		printf("%d, ",(*head)->num);
		print_queue(&(*head)->l);
	}
}
int main (int argc, char *argv[]){
	int *A;
	/*allocating memory*/
        A = (int*) calloc(argc - 1, sizeof(int));

        /*array that contains unsorted number*/
        get_array(A, argv, argc);

	node *root = NULL;
	

	int i = 0;
        for(i = 0; i < argc - 1; i++){
		insert(&root, A[i]);
        }

	printf("inorder: ");
	print_inorder(&root);
	printf("\n");
	printf("root: %d\n", root->num);
	printf("minimum: %d\n",get_minimum(&root));
	printf("maximum: %d\n",get_maximum(&root));
	printf("amount of nodes: %d\n",counting_nodes(&root));
	printf("amount of leaves: %d\n",counting_leaves(&root));		
	printf("depth: %d\n", get_depth(&root));
	printf("per level: ");
	print_level(&root);
	printf("\n");
/*	node *head = NULL;
	enqueue(&head, 10);
	enqueue(&head, 1);
	enqueue(&head, 2);
	print_queue(&head);
	printf("dequeue: %d\n", dequeue(&head)->num);
*/
}


