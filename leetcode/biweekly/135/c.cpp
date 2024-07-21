class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(k + 1), v(k + 1);
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            cnt[abs(nums[i] - nums[j])] += 1;
            int x = max(k - min(nums[i], nums[j]), max(nums[i], nums[j])) + 1;
            if (x <= k) v[x] += 1;
        }
        vector<int> sum(k + 2);
        for (int i = 0; i <= k; i++) {
            sum[i + 1] = sum[i] + v[i];
        }
        int ans = 2 * n;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int t = abs(nums[i] - nums[j]);
            int cur = sum[t + 1] * 2 + (n / 2 - sum[t + 1] - cnt[t]);
            ans = min(ans, cur);
        }
        return ans;
    }
};
