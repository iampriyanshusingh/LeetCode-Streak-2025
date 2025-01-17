class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Find set bits in num2
        int setBits = __builtin_popcount(num2); // n & n-1 logN
        int bit = 31;
        int res = 0;
        
        // Check if the bit is set in num1 and if so, set the bit in res
        while (bit >= 0 && setBits > 0) {
            if ((num1 & (1 << bit)) != 0) {
                res = res | (1 << bit);
                setBits--;
            }
            bit--;
        }
        
        // Set remaining bits if necessary
        bit = 0;
        while (setBits > 0 && bit <= 32) {
            if ((num1 & (1 << bit)) == 0) {
                res = res | (1 << bit);
                setBits--;
            }
            bit++;
        }
        
        return res;
    }
};
