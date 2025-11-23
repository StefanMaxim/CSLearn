#define SIZE 20
#define SEED 42
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/**
 * Basic Sorting Algorithms Implimented in C
 * 
 * FIRST SOME EXPLANATIONS ON ARRAYS AND POINTERS:
 * 
 * int arr[10]; here arr is of type int[10], an actual array
 * if you write: 
 * int* p;
 * p = a, a will decay to a pointer to the array, ie &a[0] or a pointer
 * to the first element
 * 
 * NORMALLY, ARRAYS DECAY WHEN PASSED TO A FUNCTION EXCEPT FOR
 * SIZEOF AND &, in which case they do not
 * 
 * OTHERWISE, you cannot pass an array to a function, just a pointer,
 * either to the first element or to the array itself
 * 
 * writing *(a+1) will be adding one INDEX, which is 4 bytes
 * in the case of integers.
 * 
 * writing *(&a + 1) will shift over an entire array of bytes
 * or 100*4 bytes
 * 
 * 
 * a[i] is synomomous with *(a+i)
 * so a[i] => adress (char*)a + i * sizeof(a[0]) (handled internally by the compiler)
 * 
 * so &a + 1 moves by 1 * sizeof(int[10]) since a is type int* []10
 * 
 * 
 * IMPORTANT: [] binds tighter than *, so
 * 
 * int* p[10] is an array named p of size 10 of integer pointers
 * int (*p)[10] whereas this is a pointer p for an array of int size 10
 * 
 * 
 * int *[10]; by itself is invalid, since no name
 * 
 * but (int *[10]) is a valid type shape, ie a type where this is 
 * array of 10 integer pointers and int (*)[10] is a pointer to an int array of size 10
 * (can be used in typecasts and sizeof operations)
 * 
 * (int (*)[10])p remember, parenthesis evaluated first, so compiler
 * first knows its a pointer, but to what, will the next this is the [10]
 * which means its a pointer to an array of 10 ints
 * 
 * 
 * IMPORTANT MISCONCEPTION:
 * THERE IS NO RUNTIME METADATA ABOUT THE ARRAY:
 * 
 * for int*  and int(*)[10] the type is known during compile, but
 * during runtime, its just an address. they are both pointers, or 
 * memory adresses. THERE IS NO HIDDEN SIZE FIELD IN MEMORY
 * 
 * its just that when you go from int (*)[10] to int[10] via dereference
 * that is done statically, so the size isnt passed from one to other
 * its just mapped over.
 * 
 * exe:
 * 
 * int a[10];
 * int (*p)[10] = &a;
 * 
 * p is just an adress like 0x1234567
 * *p just means treat the bytes at that address as an array of size 10
 * 
 * CPU never asks how big the array is, because the compiler already knows.
 * SIZEOF IS LITERALLY DONE IN COMPILETIME FOR KNOWN TYPES, ITS JUST THE KNOWN SIZES FOR THOSE TYPES
 * COMPILER KNOWS THAT AN OBJ OF int (*)[10] WILL HAVE SIZE 10 * sizeof(int) = 10 * 4 = 40. 
 * 
 * 
 */

//FUNCTION DECLARATIONS
void createArr(int* arr, int size);
void printArr(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void swap(int* element1, int* element2);
void insertionSort(int* arr, int size);
void insertionSort2(int* arr, int size);
int sequentialSearch(int* arr, int size, int element);
int binarySearch(int* arr, int size, int element);


int main()
{
    int arr[SIZE]; //the array of size SIZE we will be creating
    int position; //the position desired

    createArr(arr,SIZE);
    printArr(arr,SIZE);
    insertionSort2(arr,SIZE);
    printArr(arr,SIZE);
    printf("We want to find the position of the element 10 in the array. \n");
    position = sequentialSearch(arr,SIZE,10);
    printf("The position we found is index %d\n",position);
    printf("But this took a lot of time, which can be done more simply with binary search\n");
    position = binarySearch(arr,SIZE,10);
    printf("Using Binary Search, we obtain the same index of %d\n",position);

    return 0;
}

void createArr(int* arr, int size)
{
    int i; //index

    srand(SEED); // sets teh random seed

    for (i=0;i<size;i++)
    {
        *(arr+i) = rand() % 21 + 2; //numbers 3 to 18, or rand() % (max + 1 - min) + min
    }

}
void printArr(int* arr, int size)
{
    int i; //index
    for (i=0;i<size;i++)
    {
        printf("%1.1d ",arr[i]);
    }
    printf("\n");
}

/**
 * Binary Sort Implementation:
 * 
 * how it works: start at the top of the array and elementwise compare the elements. if in a pair one element is larger, then swap them.
 * the will make the last element in the array either the smallest or largest. Repeat this process untill all elements are in teh sorted part of
 * array
 */
void bubbleSort(int* arr, int size)
{
    int i; //outer index for tracking number of iterations
    int j; //inner index for tracking position in the array
    int temp; //temporary variable

    for (i = 1; i < size; i++)
    {
        for(j = 0; j < size-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
}

/**
 * Selection Sort:
 * 
 * loose idea: you want to go through teh loop and find the minimum value or element (by index), and then move that to where it belongs,
 * like at the end of teh array. ie 
 * 
 * use swap in the integer pointers, try to impliment the swap function using increment and decriment
 */
void selectionSort(int* arr, int size)
{
    int i; //the latter index holding where to put the found max/min
    int j; //the inded in the current array
    int idx; //the inded of the min/max of the current pass

    for (i = 1; i < size; i++)
    {
        idx = 0;
        for(j = 0; j <= size - i; j++)
        {
            //idx = 0;
            if (arr[j] > arr[idx])
            {
                idx = j;
            }
        }
        j--;
        swap(&arr[j], &arr[idx]); //the swap must not actually be swapping
    }
}
/**
 * swap function
 * 
 * lets think about hwo to do this:
 * element1 = a, element2 = b, we want it to be swapped
 * 
 * e1 = a; e2 = b
 * e1 = a+b; e2 = b
 * e2 = e2 - e1, e2 = b - (a+b) = -a
 * e1 = e1 + e2
 * e2 = e2 * -1 (this works but very large)
 * 
 * try this:
 * e1 = a, e2 = b
 * e1 += e2
 * e1 = a + b ; e2 = b
 * e2 -= e1, so e1 = a + b, e2  = - a
 * 
 */
void swap(int* element1, int* element2)
{
    int temp; //temp storage var
    /*
    *element1 += *element2;
    *element2 -= *element1;
    *element1 += *element2;
    *element2 *= -1;
    */
   temp = *element1;
   *element1 = *element2;
   *element2 = temp;


}


/**
 * Insertion sort is the hardest, try to do it again, but loosely it work like this
 * Start with a sorted array of size 1
 * then try to add the card back in to teh sorted, by copying over the cards down one element untill one free spot in the array, 
 * insert the card there
 */
void insertionSort(int* arr, int size)
{
    int i; //outer index for boundary of unsorted loop
    int j; //the inner loop boundary
    int key; //the position where to insert the current pt

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}


void insertionSort2(int* arr, int size)
{
    int i; //the first index of the unsorted array
    int j; //the last index of the sorted array
    int key; // the number that we are trying to insert into the array

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key > arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/**
 * Sequential Search
 * 
 * just a single for loop, check all values in teh array for n, and return -1 if not present
 */
int sequentialSearch(int* arr, int size, int element)
{
    int idx; //the index of the element
    int i; //index in the array when looping

    idx = -1;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            idx = i;
        }
    }
    return idx;
}


/**
 * To swap the direction of tranversal, just swap the < and > in the if
 * since if if it in least greatest order, move first back when greater, but in greatest least order you want to do the exact opposite
 */
int binarySearch(int* arr, int size, int element)
{
    int first; //the position of the bottom clamping index
    int last; //the position of the top clamping index
    int middle; //the position of the middle clamping index
    int idx; //the actual index of the point

    idx = -1;
    first = 0;
    last = size-1;

    do
    {
        middle = (first + last) / 2;
        if (element < arr[middle])
        {
            first = middle + 1;
            printf("First element is now %d\n",first);
        }
        else if (element > arr[middle])
        {
            last = middle - 1;
            printf("Last element is now %d\n",last);
        }
        else
        {
            idx = middle;
            last = first - 1; //to break the loop since you got it
        }
    } while (first <= last);
    return idx;
}