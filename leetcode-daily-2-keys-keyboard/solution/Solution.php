<?php // Solution in PHP

class Solution
{

    /**
     * Returns the minimum number of operations required to get n 'A's on the screen
     * @param Integer $n - the number of characters to get on the screen
     * @return Integer - the minimum number of operations required
     */
    function minSteps($n)
    {
        // Get the prime factors of $n
        $primeFactors = $this->getPrimeFactors($n);

        // Sum up the prime factors to get the minimum number of operations
        return array_sum($primeFactors);
    }

    /**
     * Returns an array of prime factors for a given number
     * @param Integer $number - the number to find prime factors for
     * @return array - an array of prime factors
     */
    private function getPrimeFactors($number)
    {
        $factors = [];

        $divisor = 2;

        while ($number > 1) {
            // If the number is not divisible by the current divisor, increment the divisor
            if ($number % $divisor !== 0) {
                $divisor++;
            } else {
                // If the number is divisible by the current divisor, add it to the factors array
                // and divide the number by the current divisor
                $factors[] = $divisor;
                $number = $number / $divisor;
            }
        }

        return $factors;
    }
}