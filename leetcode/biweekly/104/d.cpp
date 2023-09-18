// https://leetcode.cn/problems/power-of-heroes/description/

class Solution {
    const int mod = 1e9 + 7;
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0, ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0) sum = (sum - nums[i - 1] + nums[i]) % mod;
            else sum = (sum + nums[i]) % mod;
            ans = (ans + sum * nums[i] % mod * nums[i] % mod) % mod;
            sum = sum * 2 % mod;
        }
        return ans;
    }
};
