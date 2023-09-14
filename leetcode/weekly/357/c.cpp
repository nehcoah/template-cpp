// 2812
// https://leetcode.cn/problems/find-the-safest-path-in-a-grid/description/
// binary search, bfs

class Solution {
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (grid[i][j] == 1) q.emplace(i, j);
        }
        int cnt = 2;
        while (!q.empty()) {
            for (int k = q.size(); k; k--) {
                auto [i, j] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int ii = i + d[0], jj = j + d[1];
                    if (ii >= 0 && ii < n && jj >= 0 && jj < n && grid[ii][jj] == 0) q.emplace(ii, jj), grid[ii][jj] = cnt;
                }
            }
            cnt++;
        }
        auto check = [&](int x) {
            x++;
            if (grid[0][0] < x) return false;
            bool vis[n][n];
            memset(vis, false, sizeof(vis));
            queue<pair<int, int>> qq;
            qq.emplace(0, 0);
            vis[0][0] = 1;
            while (!qq.empty()) {
                auto [i, j] = qq.front(); qq.pop();
                for (auto& d : dirs) {
                    int ii = i + d[0], jj = j + d[1];
                    if (ii == n - 1 && jj == n - 1 && grid[ii][jj] >= x) return true;
                    if (ii >= 0 && ii < n && jj >= 0 && jj < n && !vis[ii][jj]) {
                        if (grid[ii][jj] >= x) qq.emplace(ii, jj), vis[ii][jj] = 1;
                    }
                }
            }
            return false;
        };
        int l = 0, r = 2 * n + 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
