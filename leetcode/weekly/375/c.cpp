class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = ranges::max(nums);
        int cnt = 0, n = nums.size();
        long long ans = 0;
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx) idx.push_back(i);
        }
        if (idx.size() < k) return 0;
        for (int i = k - 1; i < idx.size(); i++) {
            ans += (long long) (idx[i - k + 1] + 1) * (i == idx.size() - 1 ? n - idx[i] : idx[i + 1] - idx[i]);
        }
        return ans;
    }
};
