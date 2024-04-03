class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), pre = -1;
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                ans += 1ll * (i - 1 - pre + 1) * (i - 1 - pre) / 2;
                pre = i - 1;
            }
        }
        ans += 1ll * (n - 1 - pre + 1) * (n - 1 - pre) / 2;
        return ans;
    }
};
