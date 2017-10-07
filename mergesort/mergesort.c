#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "mergesort.h"

void merge(int aray[], int start, int mid, int end){	
	int arr_size= end - start;
	int* extra_aray;
	extra_aray = (int*) calloc(arr_size+1,sizeof(int));
	
	int first, second;
	first = start;
	second = mid;
	int copy = 0;

	while(first < mid && second < end) {
		if(aray[first] < aray[second]){
			extra_aray[copy] = aray[first];
			++first;
		} else {
			extra_aray[copy] = aray[second];
			++second;
		}
		++copy;
	}

	while(first < mid){
		extra_aray[copy] = aray[first];
		++copy;
		++first;
	}
	
	while(second < end){
		extra_aray[copy] = aray[second];
		++copy;
		++second;
	}
	extra_aray[arr_size]='\0';

	int i;
	for(i = 0; i < arr_size; ++i){
		aray[i + start] = extra_aray[i];
	}
	
	free(extra_aray);
}
		
void sort(int aray[], int start, int end){
	int size = end - start;
	if(size >= 2){
		int mid;
	        mid = (start + end) / 2;
		sort(aray, start, mid);
		sort(aray, mid, end);
		merge(aray, start, mid, end);	
	} 
}

void mergesort(int size, int values[]){
	int start = 0;
	int end = size;
	sort(values, start, end);
}
