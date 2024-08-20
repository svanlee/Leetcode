// Solution in Kotlin

class Solution {
    // Initialize a 3D array to store the results of subproblems for memoization
    private lateinit var cache: Array<Array<Array<Int?>>>

    fun stoneGameII(piles: IntArray): Int {
        // Initialize the cache with dimensions [n][n][2], where n is the number of piles
        val n = piles.size
        cache = Array(n) { Array(n + 1) { arrayOfNulls<Int>(2) } }

        // Start the recursive function with initial index 0, M = 1, and Alice's turn (true)
        return dp(piles, 0, 1, true)
    }

    private fun dp(piles: IntArray, i: Int, m: Int, aliceTurn: Boolean): Int {
        // If we have reached the end of the piles array, return 0
        if (i >= piles.size) {
            return 0
        }

        // Check if the result of the current subproblem is already cached
        val turnIndex = if (aliceTurn) 1 else 0
        cache[i][m][turnIndex]?.let { return it }

        // Initialize the score for the current turn
        var score = if (aliceTurn) 0 else Int.MAX_VALUE

        // Try all possible moves for the current turn
        var currentScore = 0
        for (pilesCanTake in 1..minOf(2 * m, piles.size - i)) {
            currentScore += piles[i + pilesCanTake - 1]

            // Recursively call the function to simulate the next turn
            val nextScore = dp(piles, i + pilesCanTake, maxOf(m, pilesCanTake), !aliceTurn)

            // Update the score based on the current turn
            score = if (aliceTurn) {
                maxOf(score, currentScore + nextScore)
            } else {
                minOf(score, nextScore)
            }
        }

        // Cache the result of the current subproblem
        cache[i][m][turnIndex] = score
        return score
    }
}