// Solution in Swift

class Solution {
    func findComplement(_ num: Int) -> Int {
        var i = 1
        
        while i <= num {
            i <<= 1
        }
        
        return (i - 1) ^ num
    }
}