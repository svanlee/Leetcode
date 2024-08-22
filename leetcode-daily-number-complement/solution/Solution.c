// Solution in C

public
class Solution
{
public
    int FindComplement(int num)
    {
        // Calculate the number of bits in the number
        int bits = (int)Math.Floor(Math.Log(num) / Math.Log(2)) + 1;

        // Create a mask with all bits set to 1 up to the calculated number of bits
        int mask = (1 << bits) - 1;

        // Return the bitwise NOT of num ANDed with the mask, which gives the complement of num
        return ~num & mask;
    }
}