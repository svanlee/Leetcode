// Solution in GO

func minSteps(n int) int {
    // Initialize the result variable to store the minimum number of steps
    res := 0
    
    // Start from 2, the smallest prime number
    i := 2
    
    // Loop until i is less than or equal to the square root of n
    for i*i <= n {
        // If n is divisible by i, it means i is a prime factor of n
        for n%i == 0 {
            // Add i to the result, as it's a prime factor
            res += i
            // Divide n by i to remove the prime factor
            n /= i
        }
        // Increment i to check the next possible prime factor
        i++
    }
    
    // If n is greater than 1, it means n is a prime number itself
    if n > 1 {
        // Add n to the result, as it's a prime factor
        res += n
    }
    
    // Return the minimum number of steps
    return res
}