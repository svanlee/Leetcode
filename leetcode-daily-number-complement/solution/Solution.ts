// Solution in TypeScript

/**
 * Finds the binary complement of a given number.
 * 
 * @param {number} num The input number.
 * @returns {number} The binary complement of the input number.
 */
function findComplement(num: number): number {
    let sum = 0; // Initialize a variable to store the sum of the flipped bits

    // Iterate over each bit in the binary representation of the input number
    for (let i = num, j = 0; i > 0; i >>= 1, j++) {
        // Check if the current bit is 0
        if ((i & 1) === 0) {
            // If the bit is 0, add the corresponding power of 2 to the sum
            sum += 2 ** j;
        }
    }

    // Return the sum, which represents the binary complement of the input number
    return sum;
}
