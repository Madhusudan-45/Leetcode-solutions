class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> reachable(n, false);
        reachable[0] = true;

        for (int i = 0; i < n; i++) {
            if (reachable[i]) {
                int farthest = min(n - 1, i + nums[i]);

                for (int j = i + 1; j <= farthest; j++) {
                    reachable[j] = true;
                }
            }
        }

        return reachable[n - 1];
    }
};