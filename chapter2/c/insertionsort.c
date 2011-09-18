#include <stdio.h>
#include <stdlib.h>


void get_array(int *A, char *argv[], int argc){
	int i = 0;
		for (i = 1; i < argc; i++){
			A[i-1] = atoi(*(argv + i));
	}
}

/*
 * Insertion sort function from cormen 
 */
void insertionsort(int *A, int n){
	int i = 0;
	for(i = 0; i < n; i++){
		int key = *(A+i);
		int j = i - 1;
		while (j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

/*
 * Main function
 */
int main(int argc, char *argv[]){
	int i, *A;

	/*allocating memory*/
	A = (int*) calloc(argc - 1, sizeof(int));

	/*array that contains unsorted number*/
	get_array(A, argv, argc);

	printf("unsorted(A): ");
	for (i = 1; i < argc; i++){
		printf("%s, ", argv[i]);
	}

	if(A == NULL){
		printf("Error: Insufficient Memory!\n");
		exit(1);
	}
	
	/*call insertion sort function*/
	insertionsort(A, argc - 1);

	printf("\ninsertionsort(A): ");
	for (i = 0; i < argc - 1; i++)
		printf("%d, ",A[i]);
	printf("\n");

	/*desallocationg memory reserved*/
	free(A);
	
	return 0;
}
