class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        auto check = [&](int r1, int r2, int c1, int c2) {
            int l = c2, r = c1, t = r2, b = r1;
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j]) {
                        l = min(l, j), r = max(r, j);
                        t = min(t, i), b = max(b, i);
                    }
                }
            }
            if (l > r || t > b) return int(1e9);
            return (r - l + 1) * (b - t + 1);
        };
        
        int ans = 1e9, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m - 1; j++) {
                ans = min(ans, check(0, i, 0, n - 1) + check(i + 1, j, 0, n - 1) + check(j + 1, m - 1, 0, n - 1));
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                ans = min(ans, check(0, m - 1, 0, i) + check(0, m - 1, i + 1, j) + check(0, m - 1, j + 1, n - 1));
            }
        }
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                ans = min(ans, check(0, i, 0, n - 1) + check(i + 1, m - 1, 0, j) + check(i + 1, m - 1, j + 1, n - 1));
                ans = min(ans, check(i + 1, m - 1, 0, n - 1) + check(0, i, 0, j) + check(0, i, j + 1, n - 1));
                ans = min(ans, check(0, m - 1, 0, j) + check(0, i, j + 1, n - 1) + check(i + 1, m - 1, j + 1, n - 1));
                ans = min(ans, check(0, i, 0, j) + check(i + 1, m - 1, 0, j) + check(0, m - 1, j + 1, n - 1));
            }
        }
        return ans;
    }
};
