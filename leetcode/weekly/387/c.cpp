class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        array<int, 3> ycnt{}, nycnt{};
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j || i + j == n - 1) && i < n / 2) ycnt[grid[i][j]] += 1;
                else if (j == n / 2 && i >= n / 2) ycnt[grid[i][j]] += 1;
                else nycnt[grid[i][j]] += 1;
            }
        }
        int ans = min({
            ycnt[1] + ycnt[2] + min(nycnt[0] + nycnt[2], nycnt[0] + nycnt[1]),
            ycnt[0] + ycnt[2] + min(nycnt[1] + nycnt[0], nycnt[1] + nycnt[2]),
            ycnt[0] + ycnt[1] + min(nycnt[2] + nycnt[0], nycnt[2] + nycnt[1])});
        return ans;
    }
};
