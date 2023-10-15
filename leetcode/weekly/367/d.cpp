class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int mod = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> suf(n, vector<int>(m));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) grid[i][j] %= mod;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) suf[i][j] = grid[i][j];
                else if (j == m - 1) suf[i][j] = (suf[i + 1][0] * grid[i][j]) % mod;
                else suf[i][j] = (suf[i][j + 1] * grid[i][j]) % mod;
            }
        }
        int mul = 1;
        vector<vector<int>> p(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == m - 1) {
                    if (i == n - 1) p[i][j] = mul;
                    else p[i][j] = (mul * suf[i + 1][0]) % mod;
                } else p[i][j] = (mul * suf[i][j + 1]) % mod;
                mul = (mul * grid[i][j]) % mod;
            }
        }
        return p;
    }
};
