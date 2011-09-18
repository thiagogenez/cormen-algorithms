#include <stdio.h>
#include <stdlib.h>


void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++){
		A[i-1] = atoi(argv[i]);
	}
}

int binarysearch(int *A, int n, int key){
	int low = 0;
	int high = n;
	int mid = 0;

	int i = 0;
	while (low <= high){
		mid = low + (high - low)/2;
		if (A[mid] == key){
			return mid;
		}
		else if (key < A[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char *argv[]){
	int i = 0;
	for (i = 1; i < argc - 2; i++){
		 if(atoi(argv[i]) > atoi(argv[i+1])){
		 	printf("array is not sorted\n");
			exit(1);
		 }
	}

	int *A,key;
	A = (int *) calloc(argc - 1, sizeof(int));
	get_array(A,argv, argc);
	key = atoi(argv[argc - 1]);

	int found = 0;
	found = binarysearch(A, argc - 3, key);
	
	if(found >= 0){
		printf("key %i was found in %i position\n", key, found);
	}
	else{
		printf("key %i not found!\n", key);
	}
	return 0;
}
