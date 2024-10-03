#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m);
    vector<ll> w(m);
    vector f(n, vector<ll>(n, 1e18));
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i] -= 1, v[i] -= 1;
        f[u[i]][v[i]] = min(f[u[i]][v[i]], w[i]);
        f[v[i]][u[i]] = f[u[i]][v[i]];
    }
    for (int i = 0; i < n; i++) f[i][i] = 0;
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][p] + f[p][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> p(k);
        for (int i = 0; i < k; i++) {
            cin >> p[i];
            p[i] -= 1;
        }
        ll ans = 1e18;
        do {
            for (int mask = 0; mask < 1 << k; mask++) {
                ll cur = 0;
                int pre = 0;
                for (int i = 0; i < k; i++) {
                    int x = u[p[i]], y = v[p[i]];
                    if (mask >> i & 1) swap(x, y);
                    cur += f[pre][x];
                    pre = y;
                    cur += w[p[i]];
                }
                cur += f[pre][n - 1];
                ans = min(ans, cur);
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
    }

    return 0;
}

