
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();

        long long k = 1LL * k1 + k2;

        vector<int> freq(100001, 0);

        int maxDiff = 0;

        // Step 1: Differences ki frequency count karo
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);

            freq[diff]++;
            maxDiff = max(maxDiff, diff);
        }

        // Step 2: Bade differences ko reduce karo
        for (int d = maxDiff; d > 0 && k > 0; d--) {

            if (freq[d] == 0) {
                continue;
            }

            // Is level ke saare differences ko
            // ek level neeche lane ki cost
            long long need = freq[d];

            if (k >= need) {
                freq[d - 1] += freq[d];
                freq[d] = 0;
                k -= need;
            } else {
                // Saare differences ko reduce nahi kar sakte
                freq[d] -= k;
                freq[d - 1] += k;
                k = 0;
            }
        }

        // Step 3: Squared differences ka sum
        long long ans = 0;

        for (int d = 0; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};
