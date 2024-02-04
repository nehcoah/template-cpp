class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, ans = numeric_limits<long long>::min();
        int n = nums.size();
        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++) {
            if (mp.contains(nums[i] - k)) {
                ans = max(ans, sum + nums[i] - mp[nums[i] - k]);
            }
            if (mp.contains(nums[i] + k)) {
                ans = max(ans, sum + nums[i] - mp[nums[i] + k]);
            }
            if (mp.contains(nums[i])) mp[nums[i]] = min(mp[nums[i]], sum);
            else mp[nums[i]] = sum;
            sum += nums[i];
        }
        return ans == numeric_limits<long long>::min() ? 0 : ans;
    }
};
