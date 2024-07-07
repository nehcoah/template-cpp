class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector x(m + 1, vector<int>(n + 1)), y(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                x[i + 1][j + 1] = x[i][j + 1] + x[i + 1][j] - x[i][j] + (grid[i][j] == 'X');
                y[i + 1][j + 1] = y[i][j + 1] + y[i + 1][j] - y[i][j] + (grid[i][j] == 'Y');
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (x[i + 1][j + 1] > 0 && x[i + 1][j + 1] == y[i + 1][j + 1]) {
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
