class Solution {
public:

    void solve(int n, int open, int close, string curr, vector<string>& ans) {

        // Saare brackets use ho gaye
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Opening bracket laga sakte hain
        if (open < n) {
            solve(n, open + 1, close, curr + '(', ans);
        }

        // Closing bracket tabhi laga sakte hain
        // jab opening brackets zyada hain
        if (close < open) {
            solve(n, open, close + 1, curr + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};
