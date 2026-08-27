class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string ans = "";
        string prefix = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            char best_c = 0;
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    best_c = c + 'a';
                    break;
                }
            }
            
            if (best_c != 0) {
                string cand = prefix;
                cand += best_c;
                
                vector<int> temp_freq = freq;
                temp_freq[best_c - 'a']--;
                
                for (int c = 0; c < 26; c++) {
                    if (temp_freq[c] > 0) {
                        cand += string(temp_freq[c], c + 'a');
                    }
                }
                
                ans = cand;
            }
            
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
                prefix += target[i];
            } else {
                break;
            }
        }
        
        return ans;
    }
};