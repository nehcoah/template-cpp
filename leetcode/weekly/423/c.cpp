class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());
        vector<long long> f(n), g(n), sum_f(mx + 1), sum_g(mx + 1);
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            if (nums[i] > 0) {
                f[i] = (f[i] + sum_f[nums[i] - 1]) % mod;
                g[i] = (g[i] + sum_g[nums[i] - 1]) % mod;
            }
            if (nums[i] < mx) {
                f[i] = (f[i] + sum_f[nums[i] + 1]) % mod;
                g[i] = (g[i] + sum_g[nums[i] + 1]) % mod;
            }
            sum_f[nums[i]] = (sum_f[nums[i]] + f[i]) % mod;
            g[i] = (g[i] + 1ll * f[i] * nums[i] % mod) % mod;
            sum_g[nums[i]] = (sum_g[nums[i]] + g[i]) % mod;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << f[i] << " " << g[i] << endl;
            ans = (ans + g[i]) % mod;
        }
        return ans;
    }
};
