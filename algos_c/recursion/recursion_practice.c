#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "recursion_practice.h"

#ifdef PALINDROME
int main(int argc, char** argv)
{
    bool status; //status as palindrome
    char* test; //the test string to use
    char* result; //the printable result of palindromeness

    if (argc != 2)
    {
        printf("Error! please insert the name of the file");
        return EXIT_FAILURE;
    }

    FILE* fp = fopen(argv[1],"r");
    if (fp == NULL)
    {
        printf("ERROR %s! failed to open file", strerror(errno));
        return EXIT_FAILURE;
    }
    
    //find, lets count the number of chars so we can malloc correctly
    int length = 0;
    char temp_char;
    while (fscanf(fp, "%c", &temp_char) == 1)
    {
        length++;
    }

    //allocate memory to store the string
    test = malloc(sizeof(char) * length);
    if (test == NULL)
    {
        printf("ERROR! %s", strerror(errno));
        fclose(fp);
        return EXIT_FAILURE;
    }

    //return to the beginning of the file, and start copying over the elements one by one
    fseek(fp,0,SEEK_SET);
    for (int i = 0; i < length; i++)
    {
        if (fscanf(fp,"%c",&temp_char) != 1)
        {
            printf("ERROR %s",strerror(errno));
            fclose(fp);
            free(test);
            return EXIT_FAILURE;
        }
        test[i] = temp_char;
    }
    fclose(fp);

    printf("Your word is %s\n", test);
    printf("Checking...\n");
    status = isPalindrome(test,strlen(test));
    result = status ? "is" : "isn't";
    printf("Your word %s a palindrome!\n", result);
    return EXIT_SUCCESS;
}
#endif

#ifdef BINARY
int main(int argc, int argv)
#endif


/**
 * Funtion that returns true if funciton is palindrome
 */

 bool isPalindrome(char* str, int length)
 {
    if (length < 0)
    {
        return false;
    }
    else if (length == 1 || length == 0)
    {
        return true;
    }

    char first = *str; // first character in the string
    char last = *(str + length - 1);
    if (first == last)
    {
        return isPalindrome(str+1,length-2);
    }
    else
    {
        return false;
    }

 }

 /**
  * Recursive function that prints integer representation in binary
  */
 void printBinary(int n)
 {
    if (n == 0)
    {
        printf("0");
    }
    else if (n == 1)
    {
        printf("1");
    }
    else
    {
        int remainder = n % 2;
        int quotient = n / 2;
        printBinary(remainder);
        printBinary(quotient);
    }

}
