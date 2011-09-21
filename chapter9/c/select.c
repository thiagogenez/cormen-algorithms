#include <stdio.h>
#include <stdlib.h>

void get_array(int *A, char *argv[], int argc){
        int i = 0;
        for (i = 1; i < argc; i++)
                A[i-1] = atoi(*(argv + i));                                                                                                                                                                                                  }


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


int select_(int *A, int p, int r, int i){
	if(p == r)
		return p;
	int q = partition(A,p,r);
	int k = q - p + 1;
	if(k == i)
		return q;
	if(i < k)
		return select_(A,p,q-1, i);
	else
		return select_(A,q+1,r,i-k);
}

int main (int argc, char *argv[]){
	int i, *A;

        /*allocating memory*/
        A = (int*) calloc(argc - 2, sizeof(int));

	/*checking if the memory is insufficient*/
        if(A == NULL){
                printf("Error: Insufficient Memory!\n");
                exit(1);
        } 

        /*array that contains unsorted number*/
        get_array(A, argv, argc - 1);

	/*ith smallest element of the array A[0..argc - 3]*/
	i = atoi(argv[argc - 1]);
	
	if(i >= argc - 1 || i <= 0){
		printf("array do not have %dth element\n",i);
		exit(0);
	}

	int found = select_(A, 0, argc - 3, i);
	printf("found: %d\n",found);
	if(found >= 0){
		printf("%dth smallest element of the array A[",i);
		int j = 0;
		for(j; j < argc - 2; j++)
			printf("%d, ",A[j]);
		printf("] is %d\n", A[found]);
	}
	else
		printf("array do not have %dth element\n",i);

	/*free memory*/
	free(A);
	return 0;
}
