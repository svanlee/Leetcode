// Solution in KOTLIN

class Solution {
    fun findComplement(num: Int): Int {
        // Calculate the number of bits in the binary representation of the input number
        var bits = num
        var bitCount = 0
        while (bits > 0) {
            bits = bits shr 1
            bitCount++
        }
        
        // Calculate the maximum number that can be represented with the same number of bits
        val max = (1 shl bitCount) - 1
        
        // The binary complement is the difference between the maximum number and the input number
        return max - num
    }
}