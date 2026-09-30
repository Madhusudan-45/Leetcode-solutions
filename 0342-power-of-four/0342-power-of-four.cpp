class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }

        // n must be a power of 2
        if ((n & (n - 1)) != 0) {
            return false;
        }

        // For power of 4, the single 1-bit must be
        // at an odd position: 1, 4, 16, 64, ...
        return (n & 0x55555555) != 0;
    }
};