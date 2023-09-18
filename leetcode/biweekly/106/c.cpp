// https://leetcode.cn/problems/movement-of-robots/description/

class Solution {
    const int mod = 1e9 + 7;
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for (int i = 0; i < n; i++) nums[i] += (s[i] == 'R' ? 1 : -1) * d;
        sort(nums.begin(), nums.end());
        long long ans = 0, pre = 0;
        for (int i = 0; i < n; i++) pre += (long long) nums[i] - nums[0];
        ans = pre;
        for (int i = 1; i < n; i++){
            pre -= ((long long) nums[i] - nums[i - 1]) * (n - i);
            ans = (ans + pre) % mod;
        }
        return ans % mod;
    }
};
