class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        const int mod = 1e9 + 7;
        auto power = [&](long long a, long long b) {
            long long ans = 1;
            for (; b; b /= 2) {
                if (b % 2) ans = ans * a % mod;
                a = a * a % mod;
            }
            return ans;
        };

        vector f(n + 1, vector<long long>(x + 1, -1));
        auto dfs = [&](auto self, int i, int j) -> long long {
            if (j == x + 1) return power(y, x);
            if (i == n) return power(y, j);
            if (f[i][j] != -1) return f[i][j];
            long long ans = 0;
            ans = (ans + self(self, i + 1, j) * j) % mod;
            ans = (ans + self(self, i + 1, j + 1) * (x - j)) % mod;
            return f[i][j] = ans;
        };
        return dfs(dfs, 0, 0);
    }
};
