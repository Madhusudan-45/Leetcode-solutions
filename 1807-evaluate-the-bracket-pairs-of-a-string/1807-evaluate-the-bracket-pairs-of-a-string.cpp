class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;

        // Store key-value pairs in map
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }
            
            // Bracket pair
            else {
                string key = "";
                i++;  // move after '('

                // Collect key until ')'
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                
                // Key does not exist
                else {
                    ans += '?';
                }
            }
        }

        return ans;
    }
};