// Solution in C++

class Solution
{
public:
    int findComplement(int num)
    {
        // Initialize a mask with the least significant bit set to 1
        int mask = 1;

        // Keep shifting the mask to the left and setting the least significant bit to 1
        // until the mask is greater than or equal to num
        while (mask < num)
        {
            mask = (mask << 1) | 1;
        }

        // Use the XOR operation to flip all bits in the given number
        // The XOR operation returns 1 if the corresponding bits are different, and 0 if they are the same
        return num ^ mask;
    }
};