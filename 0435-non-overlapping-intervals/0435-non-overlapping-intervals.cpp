class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Step 1: Sort according to ending time
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });

        // Step 2: Select first interval
        int cnt = 1;
        int lastEnd = intervals[0][1];

        // Step 3: Check remaining intervals
        for (int i = 1; i < n; i++) {

            if (intervals[i][0] >= lastEnd) {

                cnt++;

                lastEnd = intervals[i][1];
            }
        }

        // Step 4: Minimum intervals to remove
        return n - cnt;
    }
};