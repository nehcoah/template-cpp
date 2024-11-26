class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        vector f(n, vector<int>(n, -1)), g(n, vector<int>(n, -1));
        auto dfs1 = [&](auto self, int i, int j) -> int {
            if (i == n - 1 && j == n - 1) return 0;
            if (i >= j) return -1e9;
            if (f[i][j] != -1) return f[i][j];
            int ans = 0;
            ans = max(ans, self(self, i + 1, j - 1) + fruits[i][j]);
            ans = max(ans, self(self, i + 1, j) + fruits[i][j]);
            if (j < n - 1) ans = max(ans, self(self, i + 1, j + 1) + fruits[i][j]);
            return f[i][j] = ans;
        };

        auto dfs2 = [&](auto self, int i, int j) -> int {
            if (i == n - 1 && j == n - 1) return 0;
            if (i <= j) return -1e9;
            if (g[i][j] != -1) return g[i][j];
            int ans = 0;
            ans = max(ans, self(self, i - 1, j + 1) + fruits[i][j]);
            ans = max(ans, self(self, i, j + 1) + fruits[i][j]);
            if (i < n - 1) ans = max(ans, self(self, i + 1, j + 1) + fruits[i][j]);
            return g[i][j] = ans;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += fruits[i][i];
        }
        return ans + dfs1(dfs1, 0, n - 1) + dfs2(dfs2, n - 1, 0);
    }
};
