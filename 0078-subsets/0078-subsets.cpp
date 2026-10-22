class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        ans.push_back({});

        for (int i = 0; i < nums.size(); i++) {
            int size = ans.size();

            for (int j = 0; j < size; j++) {
                vector<int> temp = ans[j];

                temp.push_back(nums[i]);

                ans.push_back(temp);
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();

//         vector<vector<int>> ans;

//         for (int num = 0; num < (1 << n); num++) {
//             vector<int> list;

//             for (int i = 0; i < n; i++) {
//                 if (num & (1 << i)) {
//                     list.push_back(nums[i]);
//                 }
//             }

//             ans.push_back(list);
//         }

//         return ans;
//     }
// };
// class Solution {
// public:

//     // Saare subsets banane ke liye helper function
//     void solve(int index, vector<int>& nums,
//                vector<int>& current,
//                vector<vector<int>>& ans) {

//         // Base Case:
//         // Jab saare elements process ho gaye
//         if (index == nums.size()) {

//             // Current subset ko answer mein daal do
//             ans.push_back(current);

//             return;
//         }

//         // =========================
//         // CHOICE 1: Element ko lo
//         // =========================

//         current.push_back(nums[index]);

//         // Next element par jao
//         solve(index + 1, nums, current, ans);

//         // =========================
//         // BACKTRACK
//         // =========================

//         // Jo element liya tha usko hata do
//         current.pop_back();

//         // =========================
//         // CHOICE 2: Element ko mat lo
//         // =========================

//         solve(index + 1, nums, current, ans);
//     }


//     vector<vector<int>> subsets(vector<int>& nums) {

//         // Final answer
//         vector<vector<int>> ans;

//         // Current subset
//         vector<int> current;

//         // Index 0 se start karo
//         solve(0, nums, current, ans);

//         return ans;
//     }
// };