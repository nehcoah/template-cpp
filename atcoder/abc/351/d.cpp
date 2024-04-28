//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }

    auto check = [&](int x, int y) {
        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '#') return false;
        }
        return true;
    };

    int ans = 1, cnt = 0;
    vector vis(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.' && check(i, j) && !vis[i][j]) {
                cnt += 1;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                vis[i][j] = cnt;
                int cur = 1;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto &d : dirs) {
                        int nx = x + d[0], ny = y + d[1];
                        if (nx >= 0 && nx < h && ny >= 0 && ny < w && vis[nx][ny] != cnt && check(x, y)) {
                            cur += 1;
                            q.emplace(nx, ny);
                            vis[nx][ny] = cnt;
                        }
                    }
                }
                ans = max(ans, cur);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
