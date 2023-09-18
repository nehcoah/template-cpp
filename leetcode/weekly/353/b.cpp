// https://leetcode.cn/problems/maximum-number-of-jumps-to-reach-the-last-index/

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (abs(nums[j] - nums[i]) <= target && dp[j] != -1) dp[i] = max(dp[i], dp[j] + 1);
            }
            // cout << dp[i] << endl;
        }
        return dp[n - 1];
    }
};
