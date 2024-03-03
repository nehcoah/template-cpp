class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = nums[0];
                dp[i][1] = nums[0] ^ k;
            } else {
                dp[i][0] = max(dp[i - 1][0] + nums[i], dp[i - 1][1] + (nums[i] ^ k));
                dp[i][1] = max(dp[i - 1][1] + nums[i], dp[i - 1][0] + (nums[i] ^ k));
            }
        }
        return dp[n - 1][0];
    }
};
