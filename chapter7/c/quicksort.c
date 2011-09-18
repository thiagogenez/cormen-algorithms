#include <stdio.h>
#include <stdlib.h>

void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++){
		A[i-1] = atoi(*(argv + i));
	}
}

int partition(int *A, int p, int r){
	int i, j;
	i = p - 1;
	int x = A[r];
	
	for(j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			int aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = x;
	
	return i + 1;
}

void quick_sort(int *A, int p, int r){
	if(p < r){
		int q = partition(A,p,r);
		quick_sort(A,p, q - 1);
		quick_sort(A,q + 1,r);
	}	
}

int main (int argc, char *argv[]){
	int i, *A;

	/*allocating memory*/
	A = (int*) calloc(argc - 1, sizeof(int));

	if(A == NULL){
		printf("Error: Insufficient Memory!\n");
		exit(1);
	}
										
	/*array that contains unsorted number*/
	get_array(A, argv, argc);

	printf("unsorted(A): ");
	for (i = 1; i < argc; i++){
		printf("%s, ", argv[i]);
	}
	
	quick_sort(A, 0, argc - 2);

	printf("\nquicksort(A): ");	
	for(i = 0; i < argc -1; i++)
		printf("%d, ",A[i]);
	printf("\n");

	free(A);
	return 0;
}
