// Solution in JavaScript

/**
 * @param {number[]} piles
 * @return {number}
 */
let helper = function(piles, dp, suffixSum, i, M) {
    // Base case: if we've reached the end of the piles array, return 0
    if (i === piles.length) {
        return 0;
    }
    
    // If Alice can take all the remaining stones, return the total sum
    if (i + 2*M >= piles.length) {
        return suffixSum[i];
    }
    
    // If the result is already memoized, return it
    if (dp[i][M] !== 0) {
        return dp[i][M];
    }
    
    // Initialize the maximum stones Alice can get
    let res = 0;
    
    // Try all possible moves (1 to 2*M)
    for (let x = 1; x <= 2*M; ++x) {
        // Calculate the maximum stones Alice can get by taking x stones
        res = Math.max(res, suffixSum[i] - helper(piles, dp, suffixSum, i+x, Math.max(M, x)));
    }
    
    // Memoize the result
    return dp[i][M] = res;
}

var stoneGameII = function(piles) {
    // Edge case: if the piles array is empty, return 0
    const n = piles.length;
    if (n <= 0) {
        return 0;
    }
    
    // Initialize a 2D memoization array
    const dp = Array.from(Array(n + 1), () => Array(2 * (n + 1)).fill(0));
    
    // Calculate the suffix sum of the piles array
    let suffixSum = new Array(piles.length);
    suffixSum[suffixSum.length - 1] = piles[piles.length - 1];
    for (let i = piles.length - 2; i >= 0; --i) {
        suffixSum[i] = piles[i] + suffixSum[i + 1];
    }
    
    // Start the game from the first pile with M=1
    return helper(piles, dp, suffixSum, 0, 1);
}