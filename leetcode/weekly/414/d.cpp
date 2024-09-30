class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        const int dirs[8][2] = {
            {2, 1}, {-2, 1}, {2, -1}, {-2, -1},
            {1, 2}, {-1, 2}, {1, -2}, {-1, -2},
        };

        int n = 50, m = positions.size();
        vector dis(m + 1, vector(n, vector<int>(n, -1)));
        auto bfs = [&](int i, int x, int y) {
            queue<pair<int, int>> q;
            q.emplace(x, y);
            dis[i][x][y] = 0;
            while (!q.empty()) {
                auto [cx, cy] = q.front(); q.pop();
                for (auto [dx, dy] : dirs) {
                    int nx = dx + cx, ny = dy + cy;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && dis[i][nx][ny] == -1) {
                        q.emplace(nx, ny);
                        dis[i][nx][ny] = dis[i][cx][cy] + 1;
                    }
                }
            }
        };

        for (int i = 0; i < m; i++) {
            bfs(i, positions[i][0], positions[i][1]);
        }
        bfs(m, kx, ky);

        vector f(m + 1, vector<int>(1 << m, -1));
        auto dfs = [&](auto self, int p, int mask) {
            if (mask == (1 << m) - 1) return 0;
            if (f[p][mask] != -1) return f[p][mask];
            int cnt = __builtin_popcount(mask);
            int ans = cnt % 2 ? 1e9 : -1e9;
            for (int i = 0; i < m; i++) {
                if ((mask >> i & 1) == 0) {
                    int t = self(self, i, mask | (1 << i)) + dis[p][positions[i][0]][positions[i][1]];
                    if (cnt % 2) ans = min(ans, t);
                    else ans = max(ans, t);
                }
            }
            return f[p][mask] = ans;
        };

        return dfs(dfs, m, 0);
    }
};
