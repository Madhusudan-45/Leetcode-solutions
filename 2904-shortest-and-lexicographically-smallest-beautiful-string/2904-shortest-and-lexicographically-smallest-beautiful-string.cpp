class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> pos;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        if (pos.size() < k) {
            return "";
        }

        string ans = "";

        for (int i = 0; i + k - 1 < pos.size(); i++) {

            int left = pos[i];
            int right = pos[i + k - 1];

            string current = s.substr(left, right - left + 1);

            if (ans == "" || current.size() < ans.size()) {
                ans = current;
            }
            else if (current.size() == ans.size() && current < ans) {
                ans = current;
            }
        }

        return ans;
    }
};


// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {

//         int left = 0;
//         int ones = 0;

//         int bestLeft = -1;
//         int bestLen = INT_MAX;

//         for (int right = 0; right < s.size(); right++) {

//             if (s[right] == '1') {
//                 ones++;
//             }

//             while (ones > k) {
//                 if (s[left] == '1') {
//                     ones--;
//                 }
//                 left++;
//             }

//             if (ones == k) {

//                 while (s[left] == '0') {
//                     left++;
//                 }

//                 int len = right - left + 1;

//                 if (len < bestLen) {
//                     bestLen = len;
//                     bestLeft = left;
//                 }
//                 else if (len == bestLen &&
//                          s.compare(left, len, s, bestLeft, bestLen) < 0) {
//                     bestLeft = left;
//                 }
//             }
//         }

//         if (bestLeft == -1) {
//             return "";
//         }

//         return s.substr(bestLeft, bestLen);
//     }
// };