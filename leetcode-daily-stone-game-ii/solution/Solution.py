# Solution in Python3

class Solution:
    def stoneGameII(self, piles):
        # Create an accumulated sum table of the rest of all stores in reverse order
        # for quick checking of the total stones from a certain index to the end
        a = [*accumulate(piles[::-1])][::-1]
        
        # Define a function to calculate the maximum stones the player can get
        @lru_cache(None)
        def game(i, m): 
            # i: current index, m: current maximal move
            # If the current index plus 2 times the maximal move is greater than or equal to the length of piles,
            # it means the player can get all the remaining stones, so return the accumulated sum at the current index
            if i + 2 * m >= len(piles): 
                return a[i]
            
            # Otherwise, the player needs to consider the minimum score their rival can get
            # Initialize the minimum score to a large number
            _minScore = 2**31 - 1  

            # Try all possible moves from 1 to 2 times the maximal move
            for x in range(1, 2 * m + 1):
                # Calculate the score if the player makes x moves
                score = game(i + x, x) if x > m else game(i + x, m)
                # Update the minimum score if the current score is smaller
                if score < _minScore: 
                    _minScore = score

            # The maximum stones the player can get is the accumulated sum at the current index minus the minimum score
            return a[i] - _minScore
            
        # Call the game function with the initial state
        return game(0, 1)