class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);

        // Generate every subarray of size k
        for(int i = 0; i <= n - k; i++) {

            set<int> st;

            // Take k elements
            for(int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Every unique element appears in this subarray
            for(int x : st) {
                freq[x]++;
            }
        }

        // Find largest element present in exactly one subarray
        int ans = -1;

        for(int x = 0; x <= 50; x++) {
            if(freq[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};