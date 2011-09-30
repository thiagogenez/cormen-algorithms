#include <stdio.h>
#include <stdlib.h>


void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++)
		A[i-1] = atoi(*(argv + i));
}

void counting_sort(int *A, int *B, int n, int low, int high){
	int i,*C;
	C = (int *) calloc(high - low + 1,sizeof(int));
	
	for(i = 0; i < high - low + 1; i++)
		C[i] = 0;
	
	for(i = 0; i < n; i++)
		C[A[i] - low] = C[A[i] - low] + 1;
	for(i = 1; i < high - low + 1; i++)
		C[i] = C[i] + C[i-1];

	for(i = high - low; i >=0; i--){
		B[C[A[i] - low]] = A[i];
		C[A[i] - low] = C[A[i] - low] - 1;
	}
	
	free(C);

}

int main (int argc, char *argv[]){
	int i, *A, *B;

	/*allocating memory for unsorted array*/
	A = (int*) calloc(argc - 3, sizeof(int));

	/*allocating memory for sorted array*/
	B = (int *) calloc(argc - 3, sizeof(int));

	/*array that contains unsorted number*/
	get_array(A, argv, argc - 2);

	printf("unsorted(A): ");
	for (i = 0; i < argc - 3 ; i++)
		printf("%d, ", A[i]);
	printf("\n");

	/*get last value from argv that is k value*/
	int low = atoi(argv[argc - 2]);
	printf("low: %d\n",low);

	int high = atoi(argv[argc - 1]);
	printf("high: %d\n",high);
	
	counting_sort(A,B,argc - 3, low,high);

	for(i = 0; i < argc - 3; i++)
		printf("%d, ",B[i]);
	printf("\n");
}
