// Solution in Go

// Function to compute the minimum number of turns required to print the string
func strangePrinter(s string) int {
    // Base case: if the string is empty, no turns are required
    if len(s) == 0 {
        return 0
    }

    // Remove consecutive duplicates from the string
    var filteredChars []rune
    for _, char := range s {
        if len(filteredChars) == 0 || char != filteredChars[len(filteredChars)-1] {
            filteredChars = append(filteredChars, char)
        }
    }

    // Get the length of the filtered string
    m := len(filteredChars)

    // Create a 2D DP table to store the minimum number of turns for each subproblem
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, m)
        for j := range dp[i] {
            // Initialize the DP table with a large value
            dp[i][j] = int(1e9)
        }
    }

    // Fill the DP table with base cases: a single character can be printed in 1 turn
    for i := 0; i < m; i++ {
        dp[i][i] = 1
    }

    // Precompute the next occurrence for each character in the filtered string
    lastSeen := make(map[rune]int)
    nextOccurrence := make([]int, m)
    for i := m - 1; i >= 0; i-- {
        char := filteredChars[i]
        if pos, found := lastSeen[char]; found {
            nextOccurrence[i] = pos
        } else {
            nextOccurrence[i] = -1
        }
        lastSeen[char] = i
    }

    // Fill the DP table using dynamic programming
    for length := 2; length <= m; length++ {
        for start := 0; start <= m-length; start++ {
            end := start + length - 1
            // Initialize the minimum number of turns for the current subproblem
            dp[start][end] = dp[start+1][end] + 1
            nextPos := nextOccurrence[start]
            for nextPos != -1 && nextPos <= end {
                // Try to find a better solution by printing the current character together with the next occurrence
                if nextPos+1 <= end {
                    dp[start][end] = min(dp[start][end], dp[start][nextPos-1]+dp[nextPos+1][end])
                } else {
                    dp[start][end] = min(dp[start][end], dp[start][nextPos-1])
                }
                nextPos = nextOccurrence[nextPos]
            }
        }
    }

    // Return the minimum number of turns required to print the entire string
    return dp[0][m-1]
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}