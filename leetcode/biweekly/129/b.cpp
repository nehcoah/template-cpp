class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> r(m), c(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                r[i] += grid[i][j];
                c[j] += grid[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) ans += 1ll * (r[i] - 1) * (c[j] - 1);
            }
        }
        return ans;
    }
};
