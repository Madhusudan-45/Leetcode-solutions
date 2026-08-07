class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        // Count how many times the sorted order breaks
        int breakCount = 0;

        // Traverse the complete array
        for (int i = 0; i < n; i++) {

            // Compare current element with next element
            // % is used so that last element compares with first element
            if (nums[i] > nums[(i + 1) % n]) {
                breakCount++;
            }
        }

        // More than one break means it cannot be a sorted rotated array
        return breakCount <= 1;
    }
};