class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";

        unordered_set<string> mp;

        for (string s : words) {
            mp.insert(s);
        }

        for (string s : words) {
            bool valid = true;

            for (int i = 1; i <= s.length(); i++) {
                string prefix = s.substr(0, i);

                if (mp.find(prefix) == mp.end()) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                if (s.length() > res.length() ||
                    (s.length() == res.length() && s < res)) {
                    res = s;
                }
            }
        }

        return res;
    }
};