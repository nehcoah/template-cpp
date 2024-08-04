class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0, row = 0, col = 0;
        for (int i = 0; i < (m + 1) / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int l = j, r = n - j - 1, t = i, b = m - i - 1;
                if (l != r && t != b) {
                    int tot = grid[t][l] + grid[t][r] + grid[b][l] + grid[b][r];
                    ans += tot % 4 == 0 ? 0 : (tot % 2 == 0 ? 2 : 1);
                }
                if (l == r) col = 1;
                if (t == b) row = 1;
            }
        }
        if (row && col) {
            int x = m / 2, y = n / 2;
            ans += grid[x][y];
            int o = 0, c = 0;
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                o += grid[x][l] + grid[x][r];
                c += grid[x][l] != grid[x][r];
            }
            for (int l = 0, r = m - 1; l < r; l++, r--) {
                o += grid[l][y] + grid[r][y];
                c += grid[l][y] != grid[r][y];
            }
            ans += c;
            if (o % 4 != 0 && !c) ans += o % 4;
        } else if (row) {
            int x = m / 2, o = 0, c = 0;
            for (int l = 0, r = n - 1; l < r; l++, r--) {
                o += grid[x][l] + grid[x][r];
                c += grid[x][l] != grid[x][r];
            }
            ans += c;
            if (o % 4 != 0 && !c) ans += o % 4;
        } else if (col) {
            int x = n / 2, o = 0, c = 0;
            for (int l = 0, r = m - 1; l < r; l++, r--) {
                o += grid[l][x] + grid[r][x];
                c += grid[l][x] != grid[r][x];
            }
            ans += c;
            if (o % 4 != 0 && !c) ans += o % 4;
        }
        return ans;
    }
};
