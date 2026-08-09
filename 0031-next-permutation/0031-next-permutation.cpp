// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(), nums.end());
//     }
// };

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int ind = -1;

        // Step 1: Find the pivot
        for(int i = n - 2; i >= 0; i--) {

            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no pivot is found, array is in descending order
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element greater than pivot
        for(int i = n - 1; i > ind; i--) {

            if(nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 3: Reverse the part after pivot
        reverse(nums.begin() + ind + 1, nums.end());
    }
};