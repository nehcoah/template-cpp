class Solution {
public:
    int countWinningSequences(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();

        auto check = [&](int a, char b) {
            if (a == 0) return b == 'F' ? 0 : b == 'E' ? 1 : -1;
            if (a == 1) return b == 'W' ? 0 : b == 'F' ? 1 : -1;
            return b == 'E' ? 0 : b == 'W' ? 1 : -1;
        };

        vector f(n + 1, vector(2 * n + 1, vector<int>(4, -1)));
        auto dfs = [&](auto self, int i, int p, int pre) -> int {
            if (i == n) return p > 0;
            if (f[i][p + n][pre] != -1) return f[i][p + n][pre];
            int ans = 0;
            for (int c = 0; c < 3; c++) {
                if (c == pre) continue;
                ans = (ans + self(self, i + 1, p + check(c, s[i]), c)) % mod;
            }
            return f[i][p + n][pre] = ans;
        };

        return dfs(dfs, 0, 0, 3);
    }
};
