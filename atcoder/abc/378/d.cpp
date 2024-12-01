#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    int ans = 0;
    vector<vector<int>> vis(h, vector<int>(w));
    auto dfs = [&](auto self, int x, int y, int cnt) {
        if (cnt == k) {
            ans += 1;
            return;
        }
        for (auto [dx, dy] : dirs) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny] && s[nx][ny] == '.') {
                vis[nx][ny] = 1;
                self(self, nx, ny, cnt + 1);
                vis[nx][ny] = 0;
            }
        }
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            vis[i][j] = 1;
            dfs(dfs, i, j, 0);
            vis[i][j] = 0;
        }
    }
    cout << ans << endl;

    return 0;
}

