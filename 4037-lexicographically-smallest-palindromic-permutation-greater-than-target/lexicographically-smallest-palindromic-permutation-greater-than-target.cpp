class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int odd = 0;
        char mid = 0;
        vector<int> half_freq(26, 0);
        
        // Count frequencies and check if a palindrome is even possible
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd++;
                mid = 'a' + i;
            }
            half_freq[i] = freq[i] / 2;
        }

        if (odd > 1) return "";

        int K = n / 2;
        
        // Try to match a prefix of length L, starting from the longest possible match
        for (int L = K; L >= 0; L--) {
            vector<int> cur_freq = half_freq;
            bool can_match = true;
            string prefix = "";

            // 1. Try to match the first L characters exactly with target
            for (int i = 0; i < L; i++) {
                int c = target[i] - 'a';
                if (cur_freq[c] > 0) {
                    cur_freq[c]--;
                    prefix += target[i];
                } else {
                    can_match = false;
                    break;
                }
            }

            if (!can_match) continue; // If we don't have the characters to match this prefix, skip

            if (L == K) {
                // If we perfectly matched the entire left half
                string pal = prefix;
                if (n % 2 != 0) pal += mid;
                string rev = prefix;
                reverse(rev.begin(), rev.end());
                pal += rev;
                
                // Since the first half matches, divergence is at or after the middle.
                if (pal > target) return pal;
                
            } else {
                // 2. We matched L characters. The L-th character must be strictly > target[L]
                int req_c = target[L] - 'a';
                int placed = -1;
                
                // Find the smallest available character that is strictly greater
                for (int c = req_c + 1; c < 26; c++) {
                    if (cur_freq[c] > 0) {
                        placed = c;
                        break;
                    }
                }

                if (placed != -1) {
                    cur_freq[placed]--;
                    string h = prefix + (char)('a' + placed);

                    // 3. Fill the remaining spots of the left half with the smallest available chars
                    for (int c = 0; c < 26; c++) {
                        while (cur_freq[c] > 0) {
                            h += (char)('a' + c);
                            cur_freq[c]--;
                        }
                    }

                    // Build the final palindrome
                    string pal = h;
                    if (n % 2 != 0) pal += mid;
                    string rev = h;
                    reverse(rev.begin(), rev.end());
                    pal += rev;

                    // It's guaranteed to be > target, and since we iterate L downwards, 
                    // this is the lexicographically smallest valid string.
                    return pal; 
                }
            }
        }
        
        return "";
    }
};