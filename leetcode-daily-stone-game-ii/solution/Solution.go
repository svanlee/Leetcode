// Solution in Go

func stoneGameII(piles []int) int {
    // Get the number of piles
    n := len(piles)
    
    // Initialize a `sums` array to store cumulative sums from the end of the piles array.
    // sums[i] will store the total number of stones from pile i to the last pile.
    sums := make([]int, n + 1)
    for i := n - 1; i >= 0; i-- {
        sums[i] = sums[i + 1] + piles[i]
    }

    // Initialize a 2D dp array to store the results of subproblems.
    // dp[start][m] will represent the maximum stones that can be collected starting
    // from index `start` with a current M value of `m`.
    dp := make([][]int, n + 1)
    for idx := range dp {
        dp[idx] = make([]int, n + 1)
        for j := range dp[idx] {
            dp[idx][j] = 0
        }
    }

    // Define a recursive function `calc` to compute the maximum stones for a given
    // starting index `start` and M value `m`.
    var calc func(start, m int) int
    calc = func(start, m int) int {
        // If the starting index is out of bounds, no stones can be taken
        if start >= n {
            return 0
        }

        // Check if the result for this subproblem has already been computed
        ans := dp[start][m]
        if ans > 0 {
            return ans
        }

        // Calculate the maximum stones that can be taken for the current turn
        for i := 1; i <= 2 * m; i++ {
            // Recursively calculate the stones that can be taken in subsequent turns
            // and maximize the current answer by taking the best outcome
            ans = max(ans, sums[start] - calc(start + i, max(m, i)))
        }

        // Store the result in dp array to avoid recomputation
        dp[start][m] = ans
        return ans
    }

    // Start the calculation from the first pile with M = 1
    return calc(0, 1)
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}