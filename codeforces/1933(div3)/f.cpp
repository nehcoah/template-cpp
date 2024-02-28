#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector dis(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dis[0][0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (y < m - 1 && a[(x + 1) % n][y + 1] == 0 && dis[(x + 1) % n][y + 1] == -1) {
            dis[(x + 1) % n][y + 1] = dis[x][y] + 1;
            q.emplace((x + 1) % n, y + 1);
        }
        if (a[(x + 1) % n][y] == 0 && a[(x + 2) % n][y] == 0 && dis[(x + 2) % n][y] == -1) {
            dis[(x + 2) % n][y] = dis[x][y] + 1;
            q.emplace((x + 2) % n, y);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int c = dis[i][m - 1];
        if (c != -1) {
            if (c % n != (i + 1) % n) {
                c += (i + n + 1 - c % n) % n;
            }
            if (ans == -1 || ans > c) {
                ans = c;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
