// Solution in C#

public class Solution
{
    public int StoneGameII(int[] piles)
    {
        int n = piles.Length;
        int[,] dp = new int[n, n];
        int[] sums = new int[n];
        sums[n - 1] = piles[n - 1];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i, j] = -1;
            }
        }

        // Calculate the Prefix sum to store the number of stones
        // that are available post this particular postion
        for (int i = piles.Length - 2; i >= 0; i--)
        {
            sums[i] = sums[i + 1] + piles[i];
        }

        return DFS(piles, sums, dp, 0, 1);
    }

    private int DFS(int[] piles, int[] sums, int[,] dp, int i, int M)
    {
        // No piles left
        if (i == piles.Length)
        {
            return 0;
        }

        // store 2*M to avoid calculation again and again
        int twiceM = (M << 1);

        // Player will get all the piles
        if (i + twiceM >= piles.Length)
        {
            return sums[i];
        }

        // If already calculated for i and M combination. Return that Value.
        if (dp[i, M] != -1)
        {
            return dp[i, M];
        }

        int min = int.MaxValue;

        // Find out the min piles that can be taken By next Player
        for (int j = 1; j <= twiceM; j++)
        {
            min = Math.Min(min, DFS(piles, sums, dp, i + j, Math.Max(j, M)));
        }

        // return the number of stones.
        return dp[i, M] = sums[i] - min;
    }
}