// https://leetcode.cn/problems/maximum-element-sum-of-a-complete-subset-of-indices/

// 1, 4, 9, 16, 25, ...
// 2*1, 2*4, 2*9, 2*16, 2*25, ...
// 3*1, 3*4, 3*9, 3*16, 3*25, ...

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            long long cur = 0;
            for (int j = 1; i * j * j <= n; j++) {
                cur += nums[i * j * j - 1];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};
