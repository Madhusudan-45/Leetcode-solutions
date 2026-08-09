class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    int n = nums.size();

    if(n == 0)
        return 0;

    int longest = 1;

    unordered_set<int> st;

    // Store all elements in the set
    for(int i = 0; i < n; i++) {
        st.insert(nums[i]);
    }

    // Check every element
    for(auto it : st) {

        // If previous element is not present,
        // then this is the starting point
        if(st.find(it - 1) == st.end()) {

            int cnt = 1;
            int x = it;

            // Find consecutive elements
            while(st.find(x + 1) != st.end()) {

                x = x + 1;
                cnt = cnt + 1;
            }

            longest = max(longest, cnt);
        }
    }   
    return longest;
    }
};