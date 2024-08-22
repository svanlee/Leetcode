<?php // Solution in PHP

class Solution
{

    /**
     * Finds the binary complement of a given number.
     * 
     * @param Integer $num The input number.
     * @return Integer The binary complement of the input number.
     */
    function findComplement($num)
    {
        // Initialize a temporary variable to 1
        $tmp = 1;

        // Loop until $tmp is greater than or equal to $num
        while ($num > $tmp) {
            // Double $tmp in each iteration
            $tmp *= 2;
        }

        // If $tmp is equal to $num, it means $num is a power of 2
        if ($tmp == $num) {
            // In this case, the complement is $tmp - 1
            return $tmp - 1;
        }

        // Otherwise, the complement is $tmp - 1 - $num
        return $tmp - 1 - $num;
    }
}