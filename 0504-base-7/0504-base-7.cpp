class Solution {
public:
    string convertToBase7(int num) {

        if (num == 0) {
            return "0";
        }

        bool negative = false;

        if (num < 0) {
            negative = true;
            num = -num;
        }

        string ans = "";

        while (num > 0) {

            int rem = num % 7;

            ans += to_string(rem);

            num = num / 7;
        }

        reverse(ans.begin(), ans.end());

        if (negative) {
            ans = "-" + ans;
        }

        return ans;
    }
};