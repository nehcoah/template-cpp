class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]] |= 1 << i;
            }
        }
        int ans = 0, i = 1;
        vector f(mp.size() + 1, vector<int>(1 << m));
        f[0][0] = 0;
        for (auto it = mp.begin(); it != mp.end(); it++, i++) {
            auto [k, v] = *it;
            for (int x = 0; x < 1 << m; x++) {
                f[i][x] = max(f[i][x], f[i - 1][x]);
                for (int y = 0; y < m; y++) {
                    if ((v >> y & 1) && (x >> y & 1) == 0) f[i][x ^ (1 << y)] = max(f[i][x ^ (1 << y)], f[i - 1][x] + k);
                }
            }
        }
        for (int i = 0; i < mp.size() + 1; i++) {
            for (int x = 0; x < 1 << m; x++) {
                ans = max(ans, f[i][x]);
            }
        }
        return ans;
    }
};
