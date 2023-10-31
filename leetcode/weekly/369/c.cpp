class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> f(n, 1e18);
        for (int i = 0; i < 3; i++) f[i] = max(0, k - nums[i]);
        for (int i = 3; i < n; i++) {
            for (int j = i - 1; j > i - 4; j--) {
                f[i] = min(f[i], f[j] + max(0, k - nums[i]));
            }
        }
        return min({f[n - 3], f[n - 2], f[n - 1]});
    }
};
