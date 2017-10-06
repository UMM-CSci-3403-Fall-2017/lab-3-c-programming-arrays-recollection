#include "mergesort.h"
#include <stdlib.h>


void mergeSort(int arr[], int  x){
    int left = 0;
    int right = x;
    if (left < right){
	//Middle of the array.
        int middle = left+(right-1)/2;
	
        //Splits the arry into two
        mergeSort(arr, left+1, m);
        mergeSort(arr, middle+1, right);
        
        merge(arr, left, middle, right);
    }
}

