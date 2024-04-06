#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    const int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int n;
    cin >> n;
    vector<string> s(2);
    cin >> s[0] >> s[1];

    vector vis(2, vector<int>(n));
    queue<pair<int, int>> q;
    vis[0][0] = 1;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == 1 && y == n - 1) {
            cout << "YES\n";
            return;
        }
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < 2 && ny >= 0 && ny < n) {
                if (s[nx][ny] == '>') ny += 1;
                else ny -= 1;
                if (!vis[nx][ny]) {
                    q.emplace(nx, ny);
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    cout << "NO\n";
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
