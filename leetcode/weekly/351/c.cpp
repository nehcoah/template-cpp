// https://leetcode.cn/problems/ways-to-split-array-into-good-subarrays/description/

class Solution {
    const int mod = 1e9 + 7;
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1;
        int i = 0;
        while (i < n && nums[i] == 0) i++;
        if (i == n) return 0;
        for (; i < n; ){
            int cur = i + 1;
            while (cur < n && nums[cur] == 0) cur++;
            if (cur == n) break;
            ans = (ans * (cur - i)) % mod;
            i = cur;
        }
        return ans;
    }
};
