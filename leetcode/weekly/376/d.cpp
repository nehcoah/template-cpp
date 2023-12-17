class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        ranges::sort(nums);
        int n = nums.size();
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        auto check = [&](int x) {
            for (int i = x; i <= n; i++) {
                int l = i - x, r = i - 1;
                int m = (l + r) / 2;
                long long y = nums[m];
                long long cur = y * (m - l) - (sum[m] - sum[l]) + (sum[i] - sum[m]) - y * (i - m);
                if (cur <= k) return true;
            }
            return false;
        };
        
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
