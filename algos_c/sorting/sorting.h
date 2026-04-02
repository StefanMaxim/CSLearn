#ifndef SORTING
#define SORTING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void);
void printarr(int* arr,int n);
void selectionSort(int* arr, int n);
void selectionSortRecursive(int* arr, int n);

void bubbleSort(int* arr, int n);
void bubbleSortRecursive(int* arr, int n);

void insertionSort(int* arr, int n);
void insertionSortRecursive(int* arr, int n);

#endif