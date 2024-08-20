# Solution in Ruby

# @param {Integer[]} piles
# @return {Integer}
def stone_game_ii(piles)
    # Get the number of piles
    n = piles.length
    
    # Initialize an array to store cumulative sums from the end of the piles array.
    # sums[i] will store the total number of stones from pile i to the last pile.
    sums = Array.new(n + 1, 0)
    (n - 1).downto(0) do |i|
        sums[i] = sums[i + 1] + piles[i]
    end

    # Initialize a 2D dp array to store the results of subproblems.
    # dp[start][m] will represent the maximum stones that can be collected starting
    # from index `start` with a current M value of `m`.
    dp = Array.new(n + 1) { Array.new(n + 1, 0) }

    # Define a recursive lambda function to compute the maximum stones for a given
    # starting index `start` and M value `m`.
    calc = lambda do |start, m|
        # If the starting index is out of bounds, no stones can be taken
        return 0 if start >= n

        # Check if the result for this subproblem has already been computed
        return dp[start][m] if dp[start][m] > 0

        # Calculate the maximum stones that can be taken for the current turn
        max_stones = 0
        (1..[2 * m, n - start].min).each do |i|
            # Recursively calculate the stones that can be taken in subsequent turns
            # and maximize the current answer by taking the best outcome
            max_stones = [max_stones, sums[start] - calc.call(start + i, [m, i].max)].max
        end

        # Store the result in dp array to avoid recomputation
        dp[start][m] = max_stones
        return max_stones
    end

    # Start the calculation from the first pile with M = 1
    calc.call(0, 1)
end