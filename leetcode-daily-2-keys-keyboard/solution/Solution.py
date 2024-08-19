# Solution in PY

class Solution:
    def minSteps(self, n: int) -> int:
        # Initialize the result variable to store the minimum number of operations
        res = 0
        
        # Initialize a variable i to 2, which will be used to find the prime factors of n
        i = 2
        
        # Loop until i * i is less than or equal to n
        while i * i <= n:
            # If n is divisible by i, it means i is a prime factor of n
            while n % i == 0:
                # Add i to the result, because we need to perform i operations to get i 'A's
                res += i
                # Divide n by i, to remove the factor i from n
                n //= i
            # Increment i by 1, to check the next possible prime factor
            i += 1
        
        # If n is greater than 1, it means n is a prime number and we need to perform n operations to get n 'A's
        if n > 1:
            res += n
        
        # Return the minimum number of operations
        return res