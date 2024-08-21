// Solution in C#

public class Solution
{
    public int StrangePrinter(string s)
    {
        // Create a DP table to store the minimum number of turns for each substring
        int[,] dp = new int[s.Length, s.Length];

        // Iterate from the end of the string to the beginning (bottom-up approach)
        for (int i = s.Length - 1; 0 <= i; --i)
        {
            // Initialize the diagonal elements to 1, since a single character can be printed in 1 turn
            dp[i, i] = 1;

            // Iterate from the current character to the end of the string
            for (int j = i + 1; j < s.Length; ++j)
            {
                // Initialize the minimum number of turns for the substring [i, j] to be 1 more than the minimum number of turns for the substring [i, j-1]
                dp[i, j] = dp[i, j - 1] + 1;

                // Try to find a better option for the minimum number of turns
                for (int k = i; k < j; ++k)
                {
                    // If the character at index k is the same as the character at index j, consider printing the substring [i, k] and [k+1, j-1] separately
                    if (s[k] == s[j])
                    {
                        // Calculate the minimum number of turns for the substring [i, k] and [k+1, j-1]
                        int temp = dp[i, k] + (k + 1 <= j - 1 ? dp[k + 1, j - 1] : 0);

                        // Update the minimum number of turns for the substring [i, j] if the temporary result is smaller
                        dp[i, j] = Math.Min(dp[i, j], temp);
                    }
                }
            }
        }

        // Return the minimum number of turns for the entire string
        return dp[0, s.Length - 1];
    }
}