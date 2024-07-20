#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    const int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int h, w, y;
    cin >> h >> w >> y;
    vector a(h, vector<int>(w));
    map<int, vector<pair<int, int>>> mp, all;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            all[a[i][j]].emplace_back(i, j);
        }
    }

    for (int i = 0; i < h; i++) {
        mp[a[i][0]].emplace_back(i, 0);
        mp[a[i][w - 1]].emplace_back(i, w - 1);
    }
    for (int i = 0; i < w; i++) {
        mp[a[0][i]].emplace_back(0, i);
        mp[a[h - 1][i]].emplace_back(h - 1, i);
    }

    int ans = h * w;
    vector vis(h, vector<int>(w));
    auto check = [&](int i, int j, int p) -> void {
        if (vis[i][j]) return;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        vis[i][j] = 1;
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            ans -= 1;
            for (auto &d : dirs) {
                int nx = cx + d[0], ny = cy + d[1];
                if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && a[nx][ny] <= p) {
                    vis[nx][ny] = 1;
                    q.emplace(nx, ny);
                }
            }
        }
    };

    for (int i = 1; i <= y; i++) {
        if (all.count(i)) {
            if (mp.count(i)) {
                for (auto [cx, cy] : mp[i]) {
                    check(cx, cy, i);
                }
            }
            for (auto [cx, cy] : all[i]) {
                if (vis[cx][cy]) continue;
                for (auto &d : dirs) {
                    int nx = cx + d[0], ny = cy + d[1];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && vis[nx][ny]) {
                        check(cx, cy, i);
                        break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
