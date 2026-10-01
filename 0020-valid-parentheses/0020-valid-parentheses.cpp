class Solution {
public:
    bool isValid(string s) {

        // Stack banaya opening brackets store karne ke liye
        stack<char> st;

        // String ke har character ko traverse karo
        for(char ch : s) {

            // Agar opening bracket hai to stack me push karo
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // Agar closing bracket aaya aur stack empty hai
                // to uska koi matching opening bracket nahi hai
                if(st.empty()) {
                    return false;
                }

                // Matching bracket mila to pop kar do
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                // Matching nahi mila
                else {
                    return false;
                }
            }
        }

        // Agar stack empty hai to saare brackets match ho gaye
        return st.empty();
    }
};