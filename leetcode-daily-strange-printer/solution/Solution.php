<?php // Solution in PHP

class Solution
{

    /**
     * @param String $s
     * @return Integer
     */
    function strangePrinter($s)
    {
        // If the input string is empty, return 0
        if (empty($s)) {
            return 0;
        }

        // Remove consecutive duplicates from the input string
        $filteredChars = array();
        foreach (str_split($s) as $char) {
            if (empty($filteredChars) || $char !== end($filteredChars)) {
                $filteredChars[] = $char;
            }
        }

        // Get the length of the filtered string
        $m = count($filteredChars);

        // Create a 2D array to store the dynamic programming results
        $dp = array_fill(0, $m, array_fill(0, $m, INF));

        // Create an array to store the next occurrence of each character
        $nextOccurrence = array_fill(0, $m, -1);

        // Fill the DP table with base cases (single characters)
        for ($i = 0; $i < $m; $i++) {
            $dp[$i][$i] = 1;
        }

        // Precompute the next occurrence of each character
        $lastSeen = array();
        for ($i = $m - 1; $i >= 0; $i--) {
            $char = $filteredChars[$i];
            if (isset($lastSeen[$char])) {
                $nextOccurrence[$i] = $lastSeen[$char];
            }
            $lastSeen[$char] = $i;
        }

        // Fill the DP table
        for ($length = 2; $length <= $m; $length++) {
            for ($start = 0; $start <= $m - $length; $start++) {
                $end = $start + $length - 1;
                $dp[$start][$end] = $dp[$start + 1][$end] + 1;
                $nextPos = $nextOccurrence[$start];
                while ($nextPos !== -1 && $nextPos <= $end) {
                    $dp[$start][$end] = min($dp[$start][$end], $dp[$start][$nextPos - 1] + ($nextPos + 1 <= $end ? $dp[$nextPos + 1][$end] : 0));
                    $nextPos = $nextOccurrence[$nextPos];
                }
            }
        }

        // Return the minimum number of turns needed to print the entire string
        return $dp[0][$m - 1];
    }
}