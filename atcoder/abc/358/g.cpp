#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int dirs[5][2] = {{0, 0}, {0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    int h, w, k, si, sj;
    cin >> h >> w >> k >> si >> sj;
    si -= 1, sj -= 1;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    const int N = min(h * w, k);
    vector f(N + 1, vector(h, vector<ll>(w, -4e18)));
    f[0][si][sj] = 0;
    for (int t = 0; t < N; t++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (auto &d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 && x < h && y >= 0 && y < w) {
                        f[t + 1][x][y] = max(f[t + 1][x][y], f[t][i][j] + a[x][y]);
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = max(ans, f[N][i][j] + 1ll * (k - N) * a[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}

