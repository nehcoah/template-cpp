class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0, i = 0, j = 0;
        for (; i < n; i++) {
            if (++mp[nums[i]] > k) {
                while (j < i) {
                    mp[nums[j++]]--;
                    if (mp[nums[i]] <= k) break;
                }
            }
            ans = max(ans, i - j + 1);
        }
        ans = max(ans, i - j);
        return ans;
    }
};
