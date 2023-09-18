// https://leetcode.cn/problems/collecting-chocolates/description/

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = 1e18 + 1;
        int n = nums.size();
        int mn[n][n];
        for (int i = 0; i < n; i++) mn[i][0] = nums[i];
        for (int i = 0; i < n; i++){
            for (int j = 1; j < n; j++) mn[i][j] = min(mn[i][j - 1], nums[(i + j) % n]);
        }
        for (int i = 0; i < n; i++){
            long long cur = 0;
            for (int j = 0; j < n; j++) cur += mn[j][i];
            ans = min(ans, cur + (long long) i * x);
        }
        return ans;
    }
};
