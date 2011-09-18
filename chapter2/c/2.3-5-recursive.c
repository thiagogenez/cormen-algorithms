#include <stdio.h>
#include <stdlib.h>


void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++){
		A[i-1] = atoi(argv[i]);
	}
}

int binarysearch(int *A, int low, int high, int key){
	if(low > high){
		return -1;
	}

	int mid = (low + high) / 2;
	
	if(key > A[mid])
		return binarysearch(A, mid + 1, high, key);
	else if (key < A[mid])
		return binarysearch(A, low, mid - 1, key);
	else 
		return mid;
}
int main(int argc, char *argv[]){
	int i = 0;

	/*checking parameters*/
	if (argc == 1){
		printf("Parameters: 0 1 2 3 3, where A = [0,1,2,3] and key = 4\n");
		exit(1);
	}

	/*checking if the array is sorted*/
	for (i = 1; i < argc - 2; i++){
		 if(atoi(argv[i]) > atoi(argv[i+1])){
		 	printf("array is not sorted\n");
			exit(1);
		 }
	}

	int *A,key;

	/*allocating memory*/
	A = (int *) calloc(argc - 1, sizeof(int));
	
	/*get integer array*/
	get_array(A,argv, argc);
	
	/*get the last value from argv that is the key to search*/
	key = atoi(argv[argc - 1]);

	int found = 0;
	
	/*call binary search*/
	found = binarysearch(A,0, argc - 3, key);
	if(found >= 0){
		printf("key %i was found in %i position\n", key, found);
	}
	else{
		printf("key %i not found!\n", key);
	}

	free(A);
	return 0;
}
