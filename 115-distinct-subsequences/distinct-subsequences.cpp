class Solution {
public:
    int numDistinct(string s, string t) {
        int sourceLen = s.size();
        int targetLen = t.size();
        unsigned long long dp[sourceLen + 1][targetLen + 1];
        memset(dp, 0, sizeof(dp));
      
        for (int i = 0; i <= sourceLen; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sourceLen; ++i) {
            for (int j = 1; j <= targetLen; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
      
        return dp[sourceLen][targetLen];
    }
};
