class Solution {
public:
    bool isSubsequence(string s, string t) {

        stack<char> st;

        if (s.empty()) {
            return true;
        }

        for (char ch : s) {
            st.push(ch);
        }

        reverse(t.begin(), t.end());

        for (int i = 0; i < t.length() && !st.empty(); i++) {
            if (t[i] == st.top()) {
                st.pop();
            }
        }

        return st.empty();
    }
};