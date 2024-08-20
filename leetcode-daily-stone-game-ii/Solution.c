// Solution in C

#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int stoneGameII(int *piles, int pilesSize)
{
    // Create an accumulated sum table of the rest of all stores in reverse order
    // for quick checking of the total stones from a certain index to the end
    int a[pilesSize + 1];
    a[pilesSize] = 0;
    for (int i = pilesSize - 1; i >= 0; i--)
    {
        a[i] = a[i + 1] + piles[i];
    }

    // Define a function to calculate the maximum stones the player can get
    int dp[1001][1001];
    for (int i = 0; i <= pilesSize; i++)
    {
        for (int m = 0; m <= pilesSize; m++)
        {
            dp[i][m] = -1;
        }
    }

    int game(int i, int m)
    {
        // i: current index, m: current maximal move
        // If the current index plus 2 times the maximal move is greater than or equal to the length of piles,
        // it means the player can get all the remaining stones, so return the accumulated sum at the current index
        if (i + 2 * m >= pilesSize)
        {
            return a[i];
        }

        // If the result is already calculated, return it
        if (dp[i][m] != -1)
        {
            return dp[i][m];
        }

        // Otherwise, the player needs to consider the minimum score their rival can get
        // Initialize the minimum score to a large number
        int _minScore = 1000000;

        // Try all possible moves from 1 to 2 times the maximal move
        for (int x = 1; x <= 2 * m; x++)
        {
            // Calculate the score if the player makes x moves
            int score = game(i + x, max(m, x));
            // Update the minimum score if the current score is smaller
            _minScore = min(_minScore, score);
        }

        // The maximum stones the player can get is the accumulated sum at the current index minus the minimum score
        dp[i][m] = a[i] - _minScore;
        return dp[i][m];
    }

    // Call the game function with the initial state
    return game(0, 1);
}