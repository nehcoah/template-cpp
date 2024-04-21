class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector f(n, vector<int>(10, 1e9));
        for (int i = 0; i < n; i++) {
            vector<int> cnt(10);
            for (int j = 0; j < m; j++) {
                cnt[grid[j][i]] += 1;
            }
            for (int k = 0; k < 10; k++) {
                if (i == 0) f[i][k] = min(f[i][k], m - cnt[k]);
                else {
                    int mn = 1e9;
                    for (int t = 0; t < 10; t++) {
                        if (t != k) mn = min(mn, f[i - 1][t]);
                    }
                    f[i][k] = min(f[i][k], mn + m - cnt[k]);
                }
            }
        }
        return *min_element(f.back().begin(), f.back().end());
    }
};
