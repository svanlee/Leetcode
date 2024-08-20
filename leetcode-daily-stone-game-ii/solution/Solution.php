<?php // Solution in PHP

class Solution
{
    // Initialize a cache array to store the results of subproblems
    private array $cache = [];

    // Define a recursive function to simulate the game
    public function stoneGameII(array $piles, int $i = 0, int $m = 1, bool $aliceTurn = true): int
    {
        // Check if the result of the current subproblem is already cached
        if (isset($this->cache[$i][$m][$aliceTurn]))
            return $this->cache[$i][$m][$aliceTurn];

        // If we have reached the end of the piles array, return 0
        if (!array_key_exists($i, $piles))
            return 0;

        // Initialize the score for the current turn
        $score = $aliceTurn ? 0 : PHP_INT_MAX;

        // Try all possible moves for the current turn
        for ($pilesCanTake = 1; $pilesCanTake <= 2 * $m; $pilesCanTake++) {
            $currentScore = 0;

            // Calculate the score for the current move
            for ($pileToTake = 0; $pileToTake < $pilesCanTake; $pileToTake++) {
                if (array_key_exists($i + $pileToTake, $piles))
                    $currentScore += $piles[$i + $pileToTake];
                else
                    continue;
            }

            // Recursively call the function to simulate the next turn
            $nextScore = $this->stoneGameII($piles, $i + $pilesCanTake, max($m, $pilesCanTake), !$aliceTurn);

            // Update the score based on the current turn
            if ($aliceTurn)
                $score = max($score, $currentScore + $nextScore);
            else
                $score = min($score, $nextScore);
        }

        // Cache the result of the current subproblem
        return $this->cache[$i][$m][$aliceTurn] = $score;
    }
}