class Solution {
public:

    int getMask(int x) {
        int mask = 0;

        int primes[] = {2, 3, 5, 7};

        for (int k = 0; k < 4; k++) {
            if (x % primes[k] == 0) {
                mask = mask | (1 << k);
            }
        }

        return mask;
    }

    int maxLength(vector<int>& nums) {

        int n = nums.size();

        int ans = 2;

        for (int i = 0; i < n; i++) {

            int usedMask = getMask(nums[i]);

            bool hasConflict = false;

            for (int j = i + 1; j < n; j++) {

                int currentMask = getMask(nums[j]);

                if ((usedMask & currentMask) != 0) {
                    hasConflict = true;
                }

                usedMask = usedMask | currentMask;

                if (j == i + 1) {
                    continue;
                }

                if (hasConflict) {
                    break;
                }

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
