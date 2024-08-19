// Solution in TS

/**
 * Returns the minimum number of operations required to get n 'A's on the screen
 * @param {number} n - the number of characters to get on the screen
 * @return {number} - the minimum number of operations required
 */
const minSteps = (n: number): number => {
  /**
   * Get the prime factors of n
   * This will help us find the minimum number of operations required
   */
  const primeFactors = getPrimeFactors(n);

  /**
   * Sum up the prime factors to get the minimum number of operations
   * The reduce function is used to add up all the prime factors
   * The initial value of the accumulator (prevVal) is set to 0
   */
  return primeFactors.reduce((prevVal, currVal) => prevVal + currVal, 0);
};

/**
 * Returns an array of prime factors for a given number
 * @param {number} dividend - the number to find prime factors for
 * @return {number[]} - an array of prime factors
 */
const getPrimeFactors = (dividend: number): number[] => {
  /**
   * Initialize an empty array to store the prime factors
   */
  const primeFactors: number[] = [];

  /**
   * Initialize the divisor to 2, which is the smallest prime number
   */
  let divisor = 2;

  /**
   * Loop until the dividend is reduced to 1
   */
  while (dividend > 1) {
    /**
     * If the dividend is not divisible by the current divisor, increment the divisor
     */
    if (dividend % divisor !== 0) {
      divisor++;
    } else {
      /**
       * If the dividend is divisible by the current divisor, add it to the prime factors array
       * and divide the dividend by the current divisor
       */
      primeFactors.push(divisor);
      dividend = dividend / divisor;
    }
  }

  /**
   * Return the array of prime factors
   */
  return primeFactors;
};