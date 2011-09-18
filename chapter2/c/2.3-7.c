#include <stdio.h>
#include <stdlib.h>

void get_array(int *A, char *argv[], int argc){
	int i = 0;
	for (i = 1; i < argc; i++){
		A[i-1] = atoi(argv[i]);
	}
}

void merge(int *A, int p, int q, int r){
	int *L, *R;
	int n1, n2;
	n1 = q - p + 1;
	n2 = r - q;
	L = (int *) calloc(n1 + 1,sizeof(int));
	R = (int *) calloc(n2 + 1, sizeof(int));

	int i, j, k;
	for (i = 0; i < n1; i++){
		L[i] = A[p + i];
	}
	
	for(i = 0; i < n2; i++){
		R[i] = A[q + i + 1];
	}

	L[n1] = 9999;
	R[n2] = 9999;

	i = j = k = 0;
	for (k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}

	free(L);
	free(R);
}

void merge_sort(int *A, int p, int r){
	if(p < r){
		int q;
		q = (p + r) / 2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int* do_exercice(int *A, int n, int x){
	int i,j,k,*result;
	result = (int *) calloc(2,sizeof(int));
	i = 0;
	j = n - 1;
	while (i < j){
		if (A[i] + A[j] > x)
			j--;
		else if (A[i] + A[j] < x)
			i++;
		else{
			result[0] = i;
			result[1] = j;
			return result;
		}
	}
	return NULL;
}

int main(int argc, char *argv[]){
	
	/*checking the parameters*/
	if (argc == 1){
		printf("Parameters: 0 1 2 3 4, where A = [0,1,2,3] and x = 4\n");
		exit(1);
	}

	int *A,x;
	
	/*allocating memory*/
	A = (int *) calloc(argc - 2, sizeof(int));
		
	/*get integer array*/
	get_array(A,argv, argc - 1);

	/*get last value from argv that is x value*/
	x = atoi(argv[argc - 1]);

	/*sort the array with mergesort*/
	merge_sort(A, 0, argc - 3);
	
	int *result,i;
	
	/*checking if there are two elements in the Array that the sum of both is equal to x*/
	result = do_exercice(A, argc - 2,x);
	
	/*print the sorted array*/
	printf("mergesort(A) = ");
	for(i = 0; i < argc - 2; i++)
		printf("%d, ", A[i]);
	
	/*print if there are two elements that the sum is equal to x or not found otherwise*/
	if(result == NULL)
		printf("\nnot found!\n");
	else
		printf("\nA[%d] + A[%d] = %d\n", result[0], result[1], A[result[0]] + A[result[1]]);
	
	free(A);
	free(result);
	
	return 0;
}
