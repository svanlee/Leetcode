// Solution in Swift

class Solution {
    /**
     * Returns the minimum number of operations required to get n 'A's on the screen
     * - parameter n: the number of characters to get on the screen
     * - returns: the minimum number of operations required
     */
    func minSteps(_ n: Int) -> Int {
        // Get the prime factors of n
        let primeFactors = getPrimeFactors(n)
        
        // Sum up the prime factors to get the minimum number of operations
        return primeFactors.reduce(0, +)
    }
    
    /**
     * Returns an array of prime factors for a given number
     * - parameter number: the number to find prime factors for
     * - returns: an array of prime factors
     */
    private func getPrimeFactors(_ number: Int) -> [Int] {
        var factors: [Int] = []
        var divisor = 2
        var num = number
        
        while num > 1 {
            // If the number is not divisible by the current divisor, increment the divisor
            if num % divisor != 0 {
                divisor += 1
            } else {
                // If the number is divisible by the current divisor, add it to the factors array
                // and divide the number by the current divisor
                factors.append(divisor)
                num /= divisor
            }
        }
        
        return factors
    }
}