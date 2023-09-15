// 2789
// https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/description/
// 

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> tmp(n);
        for (int i = 0; i < n; i++) tmp[i] = nums[i];
        for (int i = n - 2; i >= 0; i--) {
            if (tmp[i] <= tmp[i + 1]) tmp[i] += tmp[i + 1];
            else ans = max(ans, tmp[i]);
        }
        ans = max(ans, tmp[0]);
        return ans;
    }
};
