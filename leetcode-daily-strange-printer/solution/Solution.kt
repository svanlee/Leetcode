// Solution in KOTLIN

class Solution {
    fun strangePrinter(s: String): Int {
        // Convert the string to a character array for easier indexing
        val arr = s.toCharArray()
        
        // Get the length of the array
        val n = arr.size
        
        // Create a 2D array dp to store the minimum number of turns for each subproblem
        val dp = Array(n) { IntArray(n) }
        
        // Initialize the diagonal elements of dp to 1, since a single character can be printed in 1 turn
        for (i in n - 1 downTo 0) {
            dp[i][i] = 1
            // Iterate from i to n-1
            for (j in i + 1 until n) {
                // If the characters at indices i and j are the same, we can print them together
                if (arr[i] == arr[j]) {
                    // The minimum number of turns is the same as the minimum number of turns for the subproblem without the last character
                    dp[i][j] = dp[i][j - 1]
                } else {
                    // Initialize minn to a large value
                    var minn = Int.MAX_VALUE
                    // Iterate from i to j-1 to find the minimum number of turns
                    for (k in i until j) {
                        // Calculate the minimum number of turns for the subproblem by combining the minimum number of turns for the left and right parts
                        minn = minOf(minn, dp[i][k] + dp[k + 1][j])
                    }
                    // Store the minimum number of turns in dp[i][j]
                    dp[i][j] = minn
                }
            }
        }
        // Return the minimum number of turns for the entire string
        return dp[0][n - 1]
    }
}