// 2841
// https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray/description/
// slide window

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }
        for (int i = k; i < nums.size(); i++) {
            if (mp.size() >= m) ans = max(ans, sum);
            if (--mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            sum -= nums[i - k];
            mp[nums[i]]++;
            sum += nums[i];
        }
        if (mp.size() >= m) ans = max(ans, sum);
        return ans;
    }
};
