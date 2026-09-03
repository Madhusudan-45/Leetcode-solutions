class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<int> common(26, 0);

        // First word ki frequency store karo
        for(char ch : words[0]) {
            common[ch - 'a']++;
        }

        // Baaki saare words
        for(int i = 1; i < words.size(); i++) {

            vector<int> current(26, 0);

            // Current word ki frequency
            for(char ch : words[i]) {
                current[ch - 'a']++;
            }

            // Minimum frequency rakho
            for(int j = 0; j < 26; j++) {
                common[j] = min(common[j], current[j]);
            }
        }

        // Answer banao
        vector<string> ans;

        for(int i = 0; i < 26; i++) {

            while(common[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                common[i]--;
            }
        }

        return ans;
    }
};

