# Solution in Ruby

# This function calculates the minimum number of steps to transform 1 to n
# by performing the following operations:
# 1. Multiply the current number by 2
# 2. Multiply the current number by 3
# The goal is to find the minimum number of operations to reach n
def min_steps(n)
  # Initialize the result variable to store the minimum number of steps
  res = 0
  
  # Start from 2, the smallest prime number
  i = 2
  
  # Loop until i is less than or equal to the square root of n
  while i*i <= n
    # If n is divisible by i, it means i is a prime factor of n
    while n % i == 0
      # Add i to the result, as it's a prime factor
      res += i
      # Divide n by i to remove the prime factor
      n /= i
    end
    
    # Increment i to check the next possible prime factor
    i += 1
  end
  
  # If n is greater than 1, it means n is a prime number itself
  if n > 1
    # Add n to the result, as it's a prime factor
    res += n
  end
  
  # Return the minimum number of steps
  return res
end