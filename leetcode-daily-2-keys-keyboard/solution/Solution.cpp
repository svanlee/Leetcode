// Solution in CPP

class Solution
{
public:
    int minSteps(int n)
    {
        // Initialize the result variable to 0
        int res = 0;

        // Iterate from 2 to sqrt(n)
        for (int i = 2; i * i <= n; i++)
        {
            // While n is divisible by i
            while (n % i == 0)
            {
                // Add i to the result
                res += i;
                // Divide n by i
                n /= i;
            }
        }

        // If n is greater than 1, add n to the result
        if (n > 1)
            res += n;

        // Return the result
        return res;
    }
};