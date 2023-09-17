// https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            long long cur = 0;
            for (int j = i; j * j / i <= n; j += i) {
                cur += nums[j * j / i - 1];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
