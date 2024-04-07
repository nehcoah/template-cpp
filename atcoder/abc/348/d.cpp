#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    int sx, sy, tx, ty;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'S') sx = i, sy = j;
            if (a[i][j] == 'T') tx = i, ty = j;
        }
    }
    vector e(h, vector<int>(w));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        r--, c--;
        cin >> e[r][c];
    }

    priority_queue<array<int, 3>> q;
    vector dis(h, vector<int>(w, -1));
    q.push({e[sx][sy], sx, sy});
    dis[sx][sy] = e[sx][sy];
    while (!q.empty()) {
        auto [t, x, y] = q.top(); q.pop();
        if (t < dis[x][y]) continue;
        if (t == 0) continue;
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] != '#') {
                int nd = max(t - 1, e[nx][ny]);
                if (nd > dis[nx][ny]) {
                    q.push({nd, nx, ny});
                    dis[nx][ny] = nd;
                }
            }
        }
    }
    cout << (dis[tx][ty] >= 0 ? "Yes\n" : "No\n");

    return 0;
}
