class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = -1e18, sum = 0;
        vector<long long> mn(k, 1e18);
        mn[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            ans = max(ans, sum - mn[i % k]);
            mn[i % k] = min(mn[i % k], sum);
        }
        return ans;
    }
};
