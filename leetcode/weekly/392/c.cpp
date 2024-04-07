class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        // 2 5 5 6 8
        // 2 3 3 3 4 8
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        if (nums[n / 2] == k) return 0;
        if (nums[n / 2] < k) {
            int t = lower_bound(nums.begin(), nums.end(), k) - nums.begin();
            return 1ll * (t - n / 2) * k - sum[t] + sum[n / 2];
        } else {
            int t = lower_bound(nums.begin(), nums.end(), k + 1) - nums.begin();
            return sum[n / 2 + 1] - sum[t] - 1ll * (n / 2 - t + 1) * k;
        }
    }
};
