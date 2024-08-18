// Solution in TS

/**
 * Finds the nth ugly number.
 * Ugly numbers are positive numbers whose only prime factors are 2, 3, or 5.
 * 
 * @param {number} n - The position of the ugly number to find.
 * @return {number} - The nth ugly number.
 */
function nthUglyNumber(n: number): number {
    // Array to store the ugly numbers, starting with the first ugly number 1.
    const uglyNumbers: number[] = [1];

    // Indices to track the position for multiples of 2, 3, and 5.
    let i2 = 0, i3 = 0, i5 = 0;

    // Generate ugly numbers until we reach the nth one.
    for (let i = 1; i < n; i++) {
        // Find the next ugly number by taking the minimum of the next multiples of 2, 3, and 5.
        const nextUglyNumber = Math.min(
            uglyNumbers[i2] * 2, // Next multiple of 2
            uglyNumbers[i3] * 3, // Next multiple of 3
            uglyNumbers[i5] * 5  // Next multiple of 5
        );

        // Add the newly calculated ugly number to the array.
        uglyNumbers.push(nextUglyNumber);

        // Increment indices to ensure we get the next unique ugly number.
        if (nextUglyNumber === uglyNumbers[i2] * 2) i2++;
        if (nextUglyNumber === uglyNumbers[i3] * 3) i3++;
        if (nextUglyNumber === uglyNumbers[i5] * 5) i5++;
    }

    // Return the nth ugly number (accounting for zero-based indexing).
    return uglyNumbers[n - 1];
}