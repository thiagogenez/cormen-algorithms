#include <stdio.h>
#include <stdlib.h>


/*
Function Insertion-Sort

-Loop Invariant: At the start of each iteration of the FOR loop, the subarray A[0..i-1] consists of
 the elements originally in A[0..i-1] but in sorted order

*Running-time complexity:
	-Worst-case:	Theta(n^2)
	-Average-case:	Theta(n^2)
	-Best-case:	Theta(n), but the array is already sorted

*Stable:
	-YES 
	-Does not change the relative order of elements with equal keys
*In-place:
	-YES 
	-Only requires a constant amount O(1) of additional memory space
*/
void insertion_sort(int *A, int len){
	int i = 0, j = 0, key = 0;
	for(i = 1; i < len; i++){
		key = *(A+i);
		j = i - 1;
		while((j >= 0) && (*(A+j) > key)){
			*(A+j+1) = *(A+j);
			j--;
		}
		*(A+j+1) = key;
	}
}

/*
Function Selection-Sort

Loop Invariant: At the start of each iteration of the FOR loop, the subarray A[0..i-1] consists of 
smallest elements of all elements of array A[0..i] and also in sorted order.


*Running-time complexity:
        -Worst-case:    Theta(n^2)
        -Average-case:  Theta(n^2)
        -Best-case:     Theta(n^2)

*Stable: 
	-NO
	-Try: [2',2'',1]
        -Change the relative order of elements with equal keys
*In-place:
	-YES 
        -Only requires a constant amount O(1) of additional memory space

*/
void selection_sort(int *A, int len){
	int i,j,smaller,aux;
	for(i = 0; i < len-1; i++){
		smaller = i;
		for(j = i + 1; j < len; j++){
			if(*(A+j) < *(A + smaller)){
				smaller = j;
			}
		}	
		if(smaller != i){
			aux = *(A+i);
			*(A+i) = *(A+smaller);
			*(A+smaller) = aux;
		}
	}
}

void merge1(int *A, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L, *R, i = 0, j = 0, k = 0;

	L = (int *) calloc(n1 + 1,sizeof(int));
	R = (int *) calloc(n2 + 1,sizeof(int));

	for(i = 0; i < n1; i++){
		*(L + i) = *(A + i + p);
	}
	
	for(j = 0; j < n2; j++){
		*(R + j) = *(A + q + j + 1);
	}

	*(L + n1) = 9999;
	*(R + n2) = 9999;

	printf("L: ");
	for(i = 0; i <=n1 ; i++)
		printf("%d - ",*(L+i));
	printf("\n");
	
	printf("R: ");
	for(i = 0; i <=n2; i++)
		printf("%d - ",*(R+i));
	printf("\n");
	
	i = 0;
	j = 0;

	for(k = p; k <= r; k++ ){
		if(*(L + i) <= *(R + j)){
			*(A + k) = *(L + i);
			i++;
		}else{
			*(A + k) = *(R + j);
			j++;
		}
	}
}

void merge(int *A, int p, int q, int r){
	int *tmp, i = 0, j = 0 , k = 0;
	int n = r - p + 1;
	printf("n: %d\n",n);	
	tmp = (int *) calloc(n, sizeof(int));
	
	for(k = 0; k < n; k++){
	
		if((p + i < q && q + j == r) || (A[p+i] < A[q + j])){
			tmp[k] = A[p + i];
			i++;
			printf("A\n");
		}

		else if((q + j < r  && p + i == q) || (A[p + i] > A[q + j])){
			tmp[k] = A[q + j];
			j++;printf("B\n");
		}
	}

	for(k = 0; k < n; k++){
		A[p + k] = tmp[k];
		printf("k[%d] = %d - ",k,tmp[k]);
	}
	printf("\n");
}

void merge_sort(int *A, int p, int r){
	if (p < r){
		int q = (r + p) / 2;
		merge_sort(A,p,q);
		merge_sort(A,q + 1,r);
		merge(A,p,q,r);
	}
}

void initialize_array(int *A, char *argv[], int len){
	int i;
	for(i = 0; i < len; i++){
		A[i] = atoi(argv[i+2]);		
	}
}

void sort(char *algorithm, int *A, int len){
	if(algorithm[0] != '-'){
		printf("Error: invalid option\n");
		printf("Try: -i -s -m");
		exit(1);
	}
	switch(algorithm[1]){
		case 'i':
			insertion_sort(A,len);
			printf("Insertion-Sort: ");
			break;
		case 's':
			selection_sort(A,len);
			printf("Selection-sort: ");
			break;
		case 'm':
			merge_sort(A,0,len - 1);
			printf("Merge-sort: ");
			break;
		default:
			printf("Error: Algorithm '-%c' not implemented\n",algorithm[1]);
			exit(1);
	}
}

int main(int argc,char *argv[]){
	if(argc < 3 ){
		printf("Usage: ./sort algorithms 3 2 3 4 5\n");
		printf("algorithms: -i(insertion-sort); -s(selection-sort)\n");
		exit(1);
	}
	
	int i = 0, *A, lenA = argc - 2; 
	char *algorithm = argv[1];
	
	A = (int*) calloc (lenA,sizeof(int));
	
	if(A == NULL){
		printf("Error: Insufficient Memory!\n");
		exit(1);
	}
	
	initialize_array(A, argv, lenA);
	sort(algorithm,A,lenA);
	
	
	for(i = 0; i < argc - 2; i++){
		printf("%d ",*(A + i)); // *(A + i) is the same A[i]
	}
	printf("\n");
	free(A);

	return 0;
} 
