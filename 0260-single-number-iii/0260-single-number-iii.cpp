class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorAll = 0;

        for (int i = 0; i < nums.size(); i++) {
            xorAll ^= static_cast<unsigned int>(nums[i]);
        }

        unsigned int mask = xorAll & (~xorAll + 1U);

        unsigned int first = 0;
        unsigned int second = 0;

        for (int i = 0; i < nums.size(); i++) {
            unsigned int x = static_cast<unsigned int>(nums[i]);

            if (x & mask) {
                first ^= x;
            } else {
                second ^= x;
            }
        }

        return {static_cast<int>(first), static_cast<int>(second)};
    }
};
