class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Step 1: Separate start and end times
        vector<int> start;
        vector<int> end;

        for (int i = 0; i < n; i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        // Step 2: Sort both arrays
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // Step 3: Initialize variables
        int i = 0;
        int j = 0;
        int active = 0;
        int ans = 0;

        // Step 4: Traverse all starting times
        while (i < n) {

            // Free all groups whose intervals have ended
            while (j < n && start[i] > end[j]) {
                active--;
                j++;
            }

            // Current interval needs a group
            active++;

            ans = max(ans, active);

            i++;
        }

        return ans;
    }
};