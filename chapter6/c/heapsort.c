#include <stdio.h>
#include <stdlib.h>

void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++){
		A[i-1] = atoi(*(argv + i));
	}
}

int get_parent(int i){
	return (i/2);
}

int get_left(int i){
	return (2*i+ 1);
}

int get_right(int i){
	return (2*i + 2);
}

void max_heapify(int *A, int i, int *h){
	int largest, left, right;
	
	left = get_left(i);
	right = get_right(i);
	
	if(left <= *h && A[left] > A[i])
		largest =  left;
	else
		largest = i;
	
	if (right <= *h && A[right] > A[largest])
		largest = right;
	
	if(largest != i){
		int aux = A[i];
		A[i] = A[largest];
		A[largest] = aux;
		max_heapify(A, largest, h);
	}
		
}
							
void build_max_heap(int *A, int n, int *h){
	int i;
	*h = n - 1;
	for (i = n/2; i >= 0; i--){
		max_heapify(A,i,h);		
	}
}

void heap_sort(int *A, int n, int *h){
	build_max_heap(A,n,h);
	int i;
	for(i = n - 1; i > 0; i--){
		int aux = A[0];
		A[0] = A[i];
		A[i] = aux;
		*h = *h  - 1;
		max_heapify(A,0,h);
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

	/*heap atribute*/
	int heap_size;
	heap_size = 0;
	
	/*call heapsort*/
	heap_sort(A, argc - 1, &heap_size);

	
	printf("\nheapsort(A): ");	
	for(i = 0; i < argc -1; i++)
		printf("%d, ",A[i]);
	printf("\n");

	free(A);
	return 0;
}
