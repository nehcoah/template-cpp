class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        int n = s.size();
        const int mod = 1e9 + 7;

        vector f(n, vector(n, vector<int>(2, -1)));
        auto dfs = [&](auto self, int i, int p, bool is_limit) -> int {
            if (i == n) {
                return !is_limit && p == 0;
            }
            if (f[i][p][is_limit] != -1) return f[i][p][is_limit];
            int ans = 0;
            int up = is_limit ? s[i] - '0' : 1;
            for (int d = 0; d <= min(p, up); d++) {
                ans = (ans + self(self, i + 1, p - d, is_limit && d == up)) % mod;
            }
            return f[i][p][is_limit] = ans;
        };

        long long ans = 0;
        vector<int> g(n);
        for (int i = 1; i < n; i++) {
            g[i] = g[__builtin_popcount(i)] + 1;
            if (g[i] <= k) {
                ans = (ans + dfs(dfs, 0, i, true)) % mod;
            }
        }
        return ans;
    }
};
