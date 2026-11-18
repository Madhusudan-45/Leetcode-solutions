class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        // Step 1: Count magazine characters
        for(int i = 0; i < magazine.size(); i++)
        {
            freq[magazine[i] - 'a']++;
        }

        // Step 2: Check ransomNote characters
        for(int i = 0; i < ransomNote.size(); i++)
        {
            freq[ransomNote[i] - 'a']--;

            if(freq[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }

        return true;
    }
};