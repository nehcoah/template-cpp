class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = moveTime.size(), n = moveTime[0].size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        vector dis(m, vector<int>(n, 2e9));
        pq.push({0, 0, 0});
        dis[0][0] = 0;
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int cur = moveTime[nx][ny] >= d ? moveTime[nx][ny] + 1 : d + 1;
                    if (cur < dis[nx][ny]) {
                        pq.push({cur, nx, ny});
                        dis[nx][ny] = cur;
                    }
                }
            }
        }
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dis[i][j] << " \n"[j == n - 1];
        //     }
        // }
        return dis[m - 1][n - 1];
    }
};
