#include"mergesort.h"
#include <stdio.h>

void merge(int arr[], int left, int middle, int right){
    int i, j, k;
    int CountLeftArry = middle - left + 1;
    int CountRightArry =  right - middle;

    int TmpArrLeft[CountLeftArry], TmpArrRight[CountRightArry];
 
    for (i = 0; i < CountLeftArry; i++)
        TmpArrLeft[i] = arr[left + i];
    for (j = 0; j < CountRightArry; j++)
        TmpArrRight[j] = arr[middle + 1+ j];
 
    i = 0, j = 0;
    k = left;
    while (i < CountLeftArry && j < CountRightArry){
        if (TmpArrLeft[i] <= TmpArrRight[j]){
            arr[k] = TmpArrLeft[i];
            i++;
        }
        else{
            arr[k] = TmpArrRight[j];
            j++;
        }
        k++;
    }
 
    while (i < CountLeftArry){
        arr[k] = TmpArrLeft[i];
        i++;
        k++;
    }
 
    while (j < CountRightArry){
        arr[k] = TmpArrRight[j];
        j++;
        k++;
    }
}

void mergeSort(int ArrToSort[], int left, int right){
	if (left < right){
	    int middle = left+(right-left)/2;

        //Splits into two sizes.
		mergeSort(ArrToSort, left, middle);
		mergeSort(ArrToSort, middle+1, right);

		merge(ArrToSort, left, middle, right);
	}
}

void printArray(int A[], int size){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

