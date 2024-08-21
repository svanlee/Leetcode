// Solution in C

#include <stdio.h>
#include <string.h>

#define MAX_N 100

int dp[MAX_N][MAX_N];

// Function to find the minimum number of turns to print the string
int strangePrinter(char *s)
{
    int n = strlen(s);

    // Initialize the dp array with -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Call the recursive function to find the minimum number of turns
    return findMinTurns(s, 0, n - 1);
}

// Recursive function to find the minimum number of turns
int findMinTurns(char *s, int start, int end)
{
    // Base case: if the start index is greater than the end index, return 0
    if (start > end)
    {
        return 0;
    }

    // If the result is already computed, return it
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }

    // Initialize the result with the length of the substring (1 + the minimum number of turns for the substring without the first character)
    int res = 1 + findMinTurns(s, start + 1, end);

    // Try to find a better option for the result
    for (int k = start + 1; k <= end; k++)
    {
        // If the current character is equal to the first character, calculate the minimum number of turns for the substring without the first and last characters
        if (s[k] == s[start])
        {
            int temp = findMinTurns(s, start, k - 1) + findMinTurns(s, k + 1, end);
            // Update the result if the temporary result is smaller
            res = (temp < res) ? temp : res;
        }
    }

    // Cache the result and return it
    dp[start][end] = res;
    return res;
}