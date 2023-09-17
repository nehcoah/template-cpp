// https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/description/

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(i) == k) ans += nums[i];
        }
        return ans;
    }
};
