// Solution in Java

class Solution {
    public int findComplement(int num) {
        // Calculate the number of bits in the given number
        int bits = (int)(Math.log(num) / Math.log(2)) + 1;
        
        // Create a mask with all bits set to 1
        int mask = (1 << bits) - 1;
        
        // Use XOR operation to flip all bits in the given number
        // The XOR operation returns 1 if the corresponding bits are different, and 0 if they are the same
        return num ^ mask;
    }
}