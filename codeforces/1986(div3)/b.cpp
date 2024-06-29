#include "bits/stdc++.h"
using namespace std;

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int m, n;
    cin >> m >> n;
    vector a(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0, tot = 0, mx = 0;
            for (auto &d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    tot += 1;
                    if (a[x][y] < a[i][j]) cnt += 1;
                    mx = max(mx, a[x][y]);
                }
            }
            if (cnt == tot) a[i][j] = mx;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
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
