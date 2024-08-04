class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = m * n;
        int cur = 0;
        for (int i = 0; i < m; i++) {
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                if (grid[i][l] != grid[i][r]) cur += 1;
            }
        }
        ans = min(ans, cur);
        cur = 0;
        for (int i = 0; i < n; i++) {
            for (int l = 0, r = m - 1; l < r; l++, r--) {
                if (grid[l][i] != grid[r][i]) cur += 1;
            }
        }
        ans = min(ans, cur);
        return ans;
    }
};
