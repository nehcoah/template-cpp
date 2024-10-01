class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0] == 1 && health == 1) return false;
        const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        vector vis(health + 1, vector(m, vector<int>(n)));
        queue<array<int, 3>> q;
        q.push({0, 0, health - grid[0][0]});
        vis[health - grid[0][0]][0][0] = 1;
        while (!q.empty()) {
            auto [x, y, h] = q.front(); q.pop();
            for (auto &[dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && h - grid[nx][ny] != 0 && !vis[h - grid[nx][ny]][nx][ny]) {
                    vis[h - grid[nx][ny]][nx][ny] = 1;
                    q.push({nx, ny, h - grid[nx][ny]});
                }
            }
        }
        bool ok = false;
        for (int i = 0; i <= health; i++) {
            ok |= vis[i][m - 1][n - 1];
        }
        return ok;
    }
};
