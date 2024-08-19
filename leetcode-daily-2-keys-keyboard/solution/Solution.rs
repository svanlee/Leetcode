// Solution in Rust

impl Solution {
    pub fn min_steps(mut n: i32) -> i32 {
        // Initialize the result variable to store the minimum number of steps
        let mut res: i32 = 0;
        
        // Start from 2, the smallest prime number
        let mut i: i32 = 2;
        
        // Loop until i is less than or equal to the square root of n
        while i * i <= n {
            // If n is divisible by i, it means i is a prime factor of n
            while n % i == 0 {
                // Add i to the result, as it's a prime factor
                res += i;
                // Divide n by i to remove the prime factor
                n /= i;
            }
            
            // Increment i to check the next possible prime factor
            i += 1;
        }
        
        // If n is greater than 1, it means n is a prime number itself
        if n > 1 {
            // Add n to the result, as it's a prime factor
            res += n;
        }
        
        // Return the minimum number of steps
        res
    }
}