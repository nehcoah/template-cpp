class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int l = n - 1, r = 0, t = m - 1, b = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    l = min(l, j), r = max(r, j);
                    t = min(t, i), b = max(b, i);
                }
            }
        }
        return (r - l + 1) * (b - t + 1);
    }
};
