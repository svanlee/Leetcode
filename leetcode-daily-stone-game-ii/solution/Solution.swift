// Solution in Swift

class Solution {
    // Initialize a cache dictionary to store the results of subproblems
    private var cache = [[[Int?]]]()
    
    func stoneGameII(_ piles: [Int]) -> Int {
        let n = piles.count
        cache = Array(repeating: Array(repeating: [Int?](repeating: nil, count: 2), count: n + 1), count: n + 1)
        return dp(piles, 0, 1, true)
    }
    
    private func dp(_ piles: [Int], _ i: Int, _ m: Int, _ aliceTurn: Bool) -> Int {
        // If we have reached the end of the piles array, return 0
        if i >= piles.count {
            return 0
        }
        
        // Check if the result of the current subproblem is already cached
        if let cachedResult = cache[i][m][aliceTurn ? 1 : 0] {
            return cachedResult
        }
        
        // Initialize the score for the current turn
        var score = aliceTurn ? 0 : Int.max
        
        // Try all possible moves for the current turn
        var currentScore = 0
        for pilesCanTake in 1...min(2 * m, piles.count - i) {
            currentScore += piles[i + pilesCanTake - 1]
            
            // Recursively call the function to simulate the next turn
            let nextScore = dp(piles, i + pilesCanTake, max(m, pilesCanTake), !aliceTurn)
            
            // Update the score based on the current turn
            if aliceTurn {
                score = max(score, currentScore + nextScore)
            } else {
                score = min(score, nextScore)
            }
        }
        
        // Cache the result of the current subproblem
        cache[i][m][aliceTurn ? 1 : 0] = score
        return score
    }
}