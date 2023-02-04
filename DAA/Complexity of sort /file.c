#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
            if(min_idx != i)
                swap(&arr[min_idx], &arr[i]);
    }
}


int main(){
    FILE *filePointer;
    FILE *filePointer2;
//    filePointer = fopen("fileName.txt", "w");
//    for(int i=0;i<99999;i++){
//        fprintf(filePointer, "%d\t",rand() % 100 + 1);
//    }
    int sorted_number = 100;
    filePointer2 = fopen("result.txt","w");
    fprintf(filePointer2,"Insertion Sort\n");
    filePointer = fopen("fileName.txt", "r");
    while(sorted_number<100000){
        int num[sorted_number];
        for(int i=0;i<sorted_number;i++){
            fscanf(filePointer,"%d",&num[i]);
        }
        clock_t t;
        t = clock();
        insertionSort(num,sorted_number);
        t = clock() - t;
        double timetaken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(filePointer2,"%f\n",timetaken);
        sorted_number += 100;
    }
    fprintf(filePointer2,"Selection Sort\n");
    int sorted_number1 = 100;
    while(sorted_number1<100000){
        int num[sorted_number1];
        for(int i=0;i<sorted_number1;i++){
            fscanf(filePointer,"%d",&num[i]);
        }
        clock_t t;
        t = clock();
        selectionSort(num,sorted_number1);
        t = clock() - t;
        double timetaken = ((double)t)/CLOCKS_PER_SEC;
        fprintf(filePointer2,"%f\n",timetaken);
        sorted_number1 += 100;
    }
    fclose(filePointer);
    return 0;
}
