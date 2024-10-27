class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector f(n, vector(mx + 1, vector<long long>(mx + 1, -1)));
        auto dfs = [&](auto self, int i, int x, int y) -> long long {
            if (i == n) return x == y;
            if (f[i][x][y] != -1) return f[i][x][y];
            long long ans = 0;
            ans = (ans + self(self, i + 1, gcd(x, nums[i]), y)) % mod;
            ans = (ans + self(self, i + 1, x, gcd(y, nums[i]))) % mod;
            ans = (ans + self(self, i + 1, x, y)) % mod;
            return f[i][x][y] = ans;
        };
        return (dfs(dfs, 0, 0, 0) - 1 + mod) % mod;
    }
};
