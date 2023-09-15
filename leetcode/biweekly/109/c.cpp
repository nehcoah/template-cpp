// 2786
// https://leetcode.cn/problems/visit-array-positions-to-maximize-score/
// dp

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        using ll = long long;
        int n = nums.size();
        vector<ll> a{nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) a.back() += nums[i];
            else a.push_back(nums[i]);
        }
        vector<ll> dp(a.size());
        dp[0] = a[0];
        for (int i = 1; i < a.size(); i++) {
            dp[i] = dp[i - 1] + a[i] - x;
            if (i >= 2) dp[i] = max(dp[i], max(dp[i - 2] + a[i], dp[i - 2] + a[i - 1] + a[i] - 2 * x));
        }
        return *max_element(dp.begin(), dp.end());
    }
};
