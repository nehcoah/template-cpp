class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> f(n + 1, -1e18);
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
            if (i > 0) f[i + 1] = max(f[i + 1], f[i - 1] + nums[i - 1] - nums[i]);
        }
        return f.back();
    }
};
