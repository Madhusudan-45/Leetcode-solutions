class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int ans = k;

        while (true) {

            bool found = false;

            for (int i = 0; i < nums.size(); i++) {

                if (nums[i] == ans) {
                    found = true;
                    break;
                }
            }

            if (found == false) {
                return ans;
            }

            ans += k;
        }
    }
};



// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {

//         set<int> s(nums.begin(), nums.end());

//         int ans = k;

//         while (s.count(ans)) {
//             ans += k;
//         }

//         return ans;
//     }
// };