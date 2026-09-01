class Solution {
public:
    string reversePrefix(string word, char ch) {

        // ch ka first occurrence find karo
        int index = word.find(ch);

        // agar ch nahi mila
        if(index == string::npos) {
            return word;
        }

        // 0 se index tak reverse karo
        reverse(word.begin(), word.begin() + index + 1);

        return word;
    }
};
