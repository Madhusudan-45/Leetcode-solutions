class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {

        unordered_map<int, int> mp;

        // Step 1: Count frequency
        for(int i = 0; i < deck.size(); i++) {
            mp[deck[i]]++;
        }

        // Step 2: Calculate GCD of all frequencies
        int g = 0;

        for(auto it : mp) {
            g = gcd(g, it.second);
        }

        // Step 3: GCD must be greater than 1
        return g > 1;
    }
};