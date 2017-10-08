#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "../mergesort/mergesort.c"

//for loops  galore, double points are fun.
int* array_merge(int num_arrays, int* sizes, int** values){
    int SC=0,tmpArry=0, begin=0, placeholder, dub=0,Keeping=0,SP=0;
    int SP3=0;
    int* Dakeeper;
    if(num_arrays == 0){
        int* emptyArry = (int*)calloc(1, sizeof(int));
        return emptyArry;
    }
    for(int i=0;i<num_arrays;i++){
        tmpArry += sizes[i];
    }
    int* full_Arry = (int*)calloc(tmpArry, sizeof(tmpArry));
    int* to_Sort = (int*)calloc(tmpArry, sizeof(tmpArry));
    for(int i = 0; i < num_arrays;i++){
        for(int j = 0; j < sizes[i]; j++){
            full_Arry[begin] = values[i][j];
            begin++;
        }
    }
    for(int i=0;i<tmpArry;i++){
        placeholder=full_Arry[i];
        placeholder==0 ? SC=1 : placeholder;
        for(int j=0;j<=SP3;j++){
            to_Sort[j]==placeholder?dub=1:placeholder;
        }
        if(dub<1){
            to_Sort[SP]=placeholder;
            Keeping ++;
            SP++;
            SP3++;
            }
            dub = 0;
    }
    SC>0 ? Keeping++ : Keeping;
    free(full_Arry);
    mergesort(Keeping, to_Sort);
    Dakeeper = (int*)calloc(Keeping+1, sizeof(Keeping));
    Dakeeper[0] = Keeping;
    for(int i = 0; i < Keeping; i++){
        Dakeeper[i+1] = to_Sort[i];
    }
    free(to_Sort);
    return Dakeeper;
}
