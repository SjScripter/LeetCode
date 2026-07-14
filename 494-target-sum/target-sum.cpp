class Solution {
public:
    int countSubsets(vector<int>& nums, int target) {
        if (target < 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];  
                if (nums[i - 1] <= j)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]]; }
        }

        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0)
            return 0;

        int newTarget = (totalSum + target) / 2;
        return countSubsets(nums, newTarget);
    }
};