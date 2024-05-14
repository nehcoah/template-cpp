class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> col(n, 1e9);
        int ans = -1e9;
        for (int i = 0; i < m; i++) {
            int mn = 1e9;
            for (int j = 0; j < n; j++) {
                mn = min(mn, col[j]);
                ans = max(ans, grid[i][j] - mn);
                col[j] = min(col[j], grid[i][j]);
                mn = min(mn, grid[i][j]);
            }
        }
        return ans;
    }
};
