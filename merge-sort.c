#include <stdio.h>
#include <math.h>

void Merge(int* A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int L[n1];
	int R[n2];
	
	getchar();
	
	printf("[ ");
	for(int i = 0; i < n1; i++)
	{
		L[i] = A[p+i];
		printf("%d ", L[i]);
	}
	printf("] - ");
	
	printf("[ ");
	for(int j = 0; j < n2; j++)
	{
		R[j] = A[q+j+1];
		printf("%d ", R[j]);	
	}
	printf("] - ");
	

	int i = 0;
	int j = 0;
	 	
	printf("[ ");
	for(int k = p; k <= r; k++)
	{
		if((L[i] <= R[j] && i < n1) || j == n2)
		{
			A[k] = L[i];
			i++;
		}
		else if((R[j] < L[i] && j < n2) || i == n1)
		{
			A[k] = R[j];
			j++;	
		}
		
		printf("%d ", A[k]);
	}
	printf("]");
	
	printf("\n");
}

void MergeSort(int* A, int p, int r)
{
	if(p == r)
	{
		return;
	}
	else
	{
		int q = floor((p+r)/2);
		//printf("%d\n",q);
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);	
		Merge(A, p, q, r);	
	}
	
}


void printArray(int* A, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("]\n");
}


int main()
{
	int A[] = {8,7,4,2,6,3};
	int n = sizeof(A)/sizeof(int);
	
	printf("Before Merge Sort: [ ");
	printArray(A,n);
	
	MergeSort(A, 0, n-1);
	
	getchar();
	printf("After Merge Sort: [ ");
	printArray(A,n);
	
	return 0;
}


