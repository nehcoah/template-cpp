class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        int ans = -1;
        for (int len = l; len <= r; len++) {
            for (int i = 0; i + len <= n; i++) {
                int cur = sum[i + len] - sum[i];
                if (cur > 0 && (cur < ans || ans == -1)) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};
