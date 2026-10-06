class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0; // unmatched '('
        int ans = 0;  // insertions needed

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                open++;
            }
            else {

                if(open > 0) {
                    open--; // match found
                }
                else {
                    ans++; // need one '('
                }
            }
        }

        // remaining '(' need ')'
        return ans + open;
    }
};