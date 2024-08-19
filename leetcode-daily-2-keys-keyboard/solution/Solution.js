// Solution in JS

/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    // Initialize the result variable to store the minimum number of operations
    let res = 0;
    
    // Initialize a variable i to 2, which will be used to find the prime factors of n
    for (let i = 2; i * i <= n; i++) {
        // If n is divisible by i, it means i is a prime factor of n
        while (n % i === 0) {
            // Add i to the result, because we need to perform i operations to get i 'A's
            res += i;
            // Divide n by i, to remove the factor i from n
            n /= i;
        }
    }
    
    // If n is greater than 1, it means n is a prime number and we need to perform n operations to get n 'A's
    if (n > 1) {
        res += n;
    }
    
    // Return the minimum number of operations
    return res;
};