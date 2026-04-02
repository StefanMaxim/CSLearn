#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

void hanoi (int n, char x, char y, char z);
int main(void);

int main()
{
    hanoi(5,'L','M','R');
}

/**
 * move n pegs from x to z using y as the temp
 * 
 * IDEA: first move the first n-1 pegs to the temp, then move the the last peg to the final spot, then move the n-1 pegs
 * to the last peg
 */
void hanoi (int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("Moving Disk %d from peg %c to peg %c\n\n",n, x, z);
        return;
    }
    else
    {
        hanoi(n-1,x,z,y);
        printf("Moving Disk %d from %c to %c\n\n",n,x,z);
        hanoi(n-1,y,x,z);
    }
}