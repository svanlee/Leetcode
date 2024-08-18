// Solution in CPP
#include <vector>
#include <algorithm> // For min function

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // Initialize the array to store ugly numbers
        std::vector<int> arr(n + 1);
        // Initialize pointers for multiples of 2, 3, and 5
        int i2 = 1, i3 = 1, i5 = 1;
        arr[1] = 1; // The first ugly number is always 1

        // Generate ugly numbers from the 2nd to the nth
        for (int i = 2; i <= n; ++i)
        {
            // Compute the next potential ugly numbers
            int i2ug = arr[i2] * 2;
            int i3ug = arr[i3] * 3;
            int i5ug = arr[i5] * 5;
            // Determine the next ugly number
            int minug = std::min(i2ug, std::min(i3ug, i5ug));
            arr[i] = minug;

            // Increment the pointers as needed
            if (minug == i2ug)
                i2++;
            if (minug == i3ug)
                i3++;
            if (minug == i5ug)
                i5++;
        }

        return arr[n]; // Return the nth ugly number
    }
};