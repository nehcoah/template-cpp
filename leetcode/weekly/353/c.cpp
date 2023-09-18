// https://leetcode.cn/problems/longest-non-decreasing-subarray-from-two-arrays/

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int dp[n][2];
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums1[i] >= nums1[i - 1]) dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            if (nums1[i] >= nums2[i - 1]) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            if (dp[i][0] == 0) dp[i][0] = 1;
            if (nums2[i] >= nums1[i - 1]) dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            if (nums2[i] >= nums2[i - 1]) dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            if (dp[i][1] == 0) dp[i][1] = 1;
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};
