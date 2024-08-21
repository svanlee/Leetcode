# Solution in Python3

class Solution:
    def strangePrinter(self, s: str) -> int:
        # Handle the edge case where the input string is empty
        if not s:
            return 0
        
        # Remove consecutive duplicates from the input string
        filtered_chars = []
        for c in s:
            if not filtered_chars or c != filtered_chars[-1]:
                filtered_chars.append(c)
        
        m = len(filtered_chars)
        
        # Initialize the dynamic programming (DP) table and last occurrence tracking
        dp = [[float('inf')] * m for _ in range(m)]
        next_occurrence = [-1] * m
        
        # Fill the DP table with base cases (each character can be printed in 1 turn)
        for i in range(m):
            dp[i][i] = 1
        
        # Precompute the next occurrence for each character in the filtered string
        last_seen = {}
        for i in range(m - 1, -1, -1):
            c = filtered_chars[i]
            if c in last_seen:
                next_occurrence[i] = last_seen[c]
            last_seen[c] = i
        
        # Fill the DP table using dynamic programming
        for length in range(2, m + 1):  # length of substring
            for start in range(m - length + 1):
                end = start + length - 1
                # Initial case: print each character separately
                dp[start][end] = dp[start + 1][end] + 1
                # Try to find a better solution by matching characters
                current_char = filtered_chars[start]
                next_pos = next_occurrence[start]
                while next_pos != -1 and next_pos <= end:
                    dp[start][end] = min(dp[start][end], dp[start][next_pos - 1] + (dp[next_pos + 1][end] if next_pos + 1 <= end else 0))
                    next_pos = next_occurrence[next_pos]
        
        # Return the minimum number of turns required to print the entire string
        return dp[0][m - 1]