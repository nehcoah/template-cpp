// https://leetcode.cn/problems/maximum-number-of-moves-in-a-grid/description/

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        bool f[m][n];
        memset(f, false, sizeof(f));
        for (int i = 0; i < m; i++) f[i][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[j][i] > grid[j][i - 1]) f[j][i] |= f[j][i - 1];
                if (j > 0 && grid[j][i] > grid[j - 1][i - 1]) f[j][i] |= f[j - 1][i - 1];
                if (j < m - 1 && grid[j][i] > grid[j + 1][i - 1]) f[j][i] |= f[j + 1][i - 1];
                if (f[j][i]) ans = i;
            }
        }
        return ans;
    }
};
