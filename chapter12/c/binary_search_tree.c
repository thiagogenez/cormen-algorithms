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
}
