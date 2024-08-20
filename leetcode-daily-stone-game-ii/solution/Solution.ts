// Solution in TypeScript

function stoneGameII(piles: number[]): number {
    // Calculate the suffix sum of the piles array
    let n = piles.length;
    let suffixSum: number[] = new Array(n).fill(0);
    suffixSum[n-1] = piles[n-1];
    for(let i=n-2; i>=0; i--){
        suffixSum[i] = piles[i] + suffixSum[i+1];
    }
    
    // Initialize a 2D memoization array
    let dp: number[][] = Array.from(Array(n + 1), () => Array(2 * (n + 1)).fill(0));
    
    // Define a helper function to simulate the game
    function helper(i: number, M: number): number {
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
        for(let x = 1; x <= 2*M; x++){
            // Calculate the maximum stones Alice can get by taking x stones
            res = Math.max(res, suffixSum[i] - helper(i+x, Math.max(M, x)));
        }
        
        // Memoize the result
        return dp[i][M] = res;
    }
    
    // Start the game from the first pile with M=1
    return helper(0, 1);
}