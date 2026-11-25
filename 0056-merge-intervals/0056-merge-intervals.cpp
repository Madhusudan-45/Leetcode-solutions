class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Step 1: Sort according to starting time
        sort(intervals.begin(), intervals.end());

        // Step 2: Create answer vector
        vector<vector<int>> ans;

        // Step 3: Traverse all intervals
        for (int i = 0; i < n; i++) {

            // If answer is empty OR no overlap
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {

                ans.push_back(intervals[i]);
            }

            // If overlap exists
            else {

                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};