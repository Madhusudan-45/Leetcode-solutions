class Solution {
public:
    void solve(int start, int target,
               vector<int>& candidates,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Case 1: Target complete ho gaya
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // Case 2: Target se aage chale gaye
        if (target < 0) {
            return;
        }

        // Har available candidate ko try karo
        for (int i = start; i < candidates.size(); i++) {

            // Current number choose karo
            current.push_back(candidates[i]);

            // Same index se dobara try kar sakte hain
            solve(i, target - candidates[i],
                  candidates, current, ans);

            // Backtracking: choice undo karo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, target, candidates, current, ans);

        return ans;
    }
};
