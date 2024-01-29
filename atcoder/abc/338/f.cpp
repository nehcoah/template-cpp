#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int inf = 0x3f3f3f3f;

    int n, m;
    cin >> n >> m;
    vector w(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        w[u][v] = min(w[u][v], x);
    }
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
            }
        }
    }

    vector f(n, vector<int>(1 << n, inf));
    for (int i = 0; i < n; i++) {
        f[i][1 << i] = 0;
    }
    for (int mask = 1; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i & 1) == 0) continue;
            if (f[i][mask] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) continue;
                if (w[i][j] == inf) continue;
                f[j][mask | 1 << j] = min(f[j][mask | 1 << j], f[i][mask] + w[i][j]);
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f[i][(1 << n) - 1]);
    }
    if (ans == inf) cout << "No" << endl;
    else cout << ans << endl;

    return 0;
}
