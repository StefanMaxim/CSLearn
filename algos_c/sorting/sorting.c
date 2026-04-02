#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "sorting.h"
#include <stdbool.h>

int main()
{
    int arr[] = {7,3,4,1,2,5,6};
    selectionSort(arr,7);
    printarr(arr,7);
}


void printarr(int* arr,int n)
{
    int i; 

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}


/**
 * IDEA: repeatedly search through the array, finding the largest/smallest element and bringing it to the front
 * 
 * TRICKS: start j from i as to not oversort
 */
void selectionSort(int* arr, int n)
{
    int i; /* looping variable for outer loop */
    int j; /* looping var for inner loop */

    for (i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            printf("swapping index %d with %d\n", arr[i], arr[min_idx]);
        }
    }
}

void selectionSortRecursive(int* arr, int n)
{
    int i;
    int j;

    if (n == 1)
    {
        return;
    }

    int i = 0;
    int max_idx = i;
    for (j = i+1; j < n; j++)
    {
        if (arr[j] > arr[max_idx])
        {
            max_idx = j;
        }
    }
    if (max_idx != i)
    {
        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }
    selectionSortRecursive(arr+1,n-1);
}

/**
 * IDEA: here, you start from the top and bubble elements up, via element-wise comparison 
 * similar to selection sort, but unstable
 * 
 * TRICKS: to not bubble to the way top bc pre-bubbled, also, if sorted dont bubble using sorted
 * double loop, one count ## of times new bubble chosed, used to rpevent over
 */
void bubbleSort(int* arr, int n)
{
    int i;
    int j;

    for (i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = false;
            }
        }
        if (sorted == true)
        {
            break;
        }
    }
}

void bubbleSortRecursive(int* arr, int n)
{
    int j;

    if (n == 1) {return;}
    for (j = 0; j < n-1; j++)
    {
        if (arr[j] > arr[j+1])
        {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
    bubbleSortRecursive(arr,n-1);
    
}

/**
 * IDEA: for loop and while loop, start from 1 and then insert that cart into the previous using a while loop 
 * (i=j tech with loop at 1, remember the temp and j for decriment)
 */
void insertionSort(int* arr, int n)
{
    
}



/** 
 * use the i=j implimentation, rest is standard
 */
void insertionSortRecursive(int* arr, int n)
{
    int i;
    int j;
    int temp;

    if (n == 1) {return;}
    insertionSortRecursive(arr,n-1);
    i=n-1;

    j=i;
    temp = arr[i];
    while(j > 0 && arr[j-1] > temp)
    {
        arr[j] = arr[j-1];
        j--;
    }
    arr[j] = temp;
    
}

void merge_sort(int* arr, int l, int r)
{
    if (l == r) {return;}

    int m = (l+r)/2;

    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
}

void merge(int* arr, int l, int m, int r)
{
    
}
