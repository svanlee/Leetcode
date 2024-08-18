// Solution in C

#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum of three integers
int min(int a, int b, int c)
{
    if (a < b)
    {
        return (a < c) ? a : c;
    }
    else
    {
        return (b < c) ? b : c;
    }
}

// Function to find the nth ugly number
int nthUglyNumber(int n)
{
    // Allocate memory to store the first n ugly numbers
    int *ugly = (int *)malloc(n * sizeof(int));
    if (!ugly)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the first ugly number
    ugly[0] = 1;

    // Initialize pointers for factors 2, 3, and 5
    int i2 = 0, i3 = 0, i5 = 0;

    // Initialize the next multiples of 2, 3, and 5
    int next2 = 2, next3 = 3, next5 = 5;

    // Generate ugly numbers until the nth number is found
    for (int i = 1; i < n; i++)
    {
        // Find the next ugly number
        int nextUgly = min(next2, next3, next5);
        ugly[i] = nextUgly;

        // Update the next multiple of 2, 3, or 5
        if (nextUgly == next2)
        {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (nextUgly == next3)
        {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (nextUgly == next5)
        {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }

    // Get the nth ugly number and free the allocated memory
    int result = ugly[n - 1];
    free(ugly);
    return result;
}
