// 2845
// https://leetcode.cn/problems/count-of-interesting-subarrays/description/
// slide window, modulo

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size(), sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + (nums[i] % modulo == k);
        unordered_map<int, int> mp;
        long long ans = 0;
        mp[0] = 1;
        for (int i = 0; i < n; i++) {
            ans += mp[(sum[i + 1] - k + modulo) % modulo];
            mp[sum[i + 1] % modulo]++;
        }
        return ans;
    }
};
