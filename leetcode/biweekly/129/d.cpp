class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        vector f(zero + 1, vector(one + 1, vector<int>(2, -1)));
        auto dfs = [&](auto self, int z, int o, int p) -> long long {
            if (z == 0) return p == 1 && o <= limit;
            if (o == 0) return p == 0 && z <= limit;
            if (f[z][o][p] != -1) return f[z][o][p];
            long long ans = 0;
            if (p == 0) {
                ans = (self(self, z - 1, o, 0) + self(self, z - 1, o, 1)) % mod;
                if (z > limit) ans = (ans - self(self, z - limit - 1, o, 1) + mod) % mod;
            } else {
                ans = (self(self, z, o - 1, 0) + self(self, z, o - 1, 1)) % mod;
                if (o > limit) ans = (ans - self(self, z, o - limit - 1, 0) + mod) % mod;
            }
            return f[z][o][p] = ans;
        };
        return (dfs(dfs, zero, one, 0) + dfs(dfs, zero, one, 1)) % mod;
    }
};
