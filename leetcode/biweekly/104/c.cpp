// https://leetcode.cn/problems/maximum-or/

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long x[n + 1];
        memset(x, 0, sizeof(x));
        for (int i = n - 1; i >= 0; i--) x[i] = x[i + 1] | nums[i];
        long long ans = 0, cur = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, cur | x[i + 1] | ((long long)nums[i] << k));
            cur |= nums[i];
        }
        return ans;
    }
};
