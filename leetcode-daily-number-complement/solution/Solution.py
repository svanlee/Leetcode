# Solution in Python3

class Solution:
    def findComplement(self, num: int) -> int:
        # Initialize an empty list to store the binary representation of the number
        arr = []
        
        # Initialize a variable to store the total value of the complement
        total = 0
        
        # Convert the number to binary by repeatedly dividing by 2 and appending the remainder
        while num >= 1:
            arr.append(num % 2)
            num = num // 2
        
        # Iterate over the binary representation in reverse order
        for i in arr[::-1]:
            # Flip the bit by subtracting it from 1 (i.e., 0 becomes 1 and 1 becomes 0)
            val = abs(i - 1)
            
            # Build the total value of the complement by shifting the current total left by 1 bit and adding the flipped bit
            total = ((total * 2) + val)
        
        # Return the total value of the complement
        return total