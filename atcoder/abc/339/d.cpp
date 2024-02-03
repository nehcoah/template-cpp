#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'P') {
                if (x1 == -1) x1 = i, y1 = j;
                else x2 = i, y2 = j;
            }
        }
    }

    auto check = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    };

    const int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    queue<array<int, 4>> q;
    q.push({x1, y1, x2, y2});
    vector vis(n, vector(n, vector(n, vector<int>(n))));
    vis[x1][y1][x2][y2] = true;

    int ans = 0;
    while (!q.empty()) {
        for (int i = q.size(); i > 0; i--) {
            auto [a, b, c, d] = q.front();
            q.pop();
            if (a == c && b == d) {
                cout << ans << endl;
                return 0;
            }
            for (auto &t : dirs) {
                int na = a + t[0], nb = b + t[1], nc = c + t[0], nd = d + t[1];
                if (!check(na, nb) || s[na][nb] == '#') na = a, nb = b;
                if (!check(nc, nd) || s[nc][nd] == '#') nc = c, nd = d;
                if (na == a && nb == b && nc == c && nd == d) continue;
                if (vis[na][nb][nc][nd]) continue;
                vis[na][nb][nc][nd] = true;
                q.push({na, nb, nc, nd});
            }
        }
        ans++;
    }


    cout << -1 << endl;

    return 0;
}
