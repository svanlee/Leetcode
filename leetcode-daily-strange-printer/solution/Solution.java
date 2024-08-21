// Solution in Java

class Solution {
    public int strangePrinter(String s) {
        if (s.isEmpty()) return 0;
        
        // Remove consecutive duplicates from the input string
        StringBuilder filteredStr = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (filteredStr.length() == 0 || c != filteredStr.charAt(filteredStr.length() - 1)) {
                filteredStr.append(c);
            }
        }
        
        int m = filteredStr.length();
        
        // Initialize the dynamic programming (DP) table and last occurrence tracking
        int[][] dp = new int[m][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        int[] nextOccurrence = new int[m];
        for (int i = 0; i < m; i++) {
            nextOccurrence[i] = -1;
        }
        
        // Fill the DP table with base cases (each character can be printed in 1 turn)
        for (int i = 0; i < m; i++) {
            dp[i][i] = 1;
        }
        
        // Precompute the next occurrence for each character in the filtered string
        Map<Character, Integer> lastSeen = new HashMap<>();
        for (int i = m - 1; i >= 0; i--) {
            char c = filteredStr.charAt(i);
            if (lastSeen.containsKey(c)) {
                nextOccurrence[i] = lastSeen.get(c);
            }
            lastSeen.put(c, i);
        }
        
        // Fill the DP table using dynamic programming
        for (int length = 2; length <= m; length++) {  // length of substring
            for (int start = 0; start <= m - length; start++) {
                int end = start + length - 1;
                // Initial case: print each character separately
                dp[start][end] = dp[start + 1][end] + 1;
                // Try to find a better solution by matching characters
                char currentChar = filteredStr.charAt(start);
                int nextPos = nextOccurrence[start];
                while (nextPos != -1 && nextPos <= end) {
                    dp[start][end] = Math.min(dp[start][end], dp[start][nextPos - 1] + (nextPos + 1 <= end ? dp[nextPos + 1][end] : 0));
                    nextPos = nextOccurrence[nextPos];
                }
            }
        }
        
        // Return the minimum number of turns required to print the entire string
        return dp[0][m - 1];
    }
}