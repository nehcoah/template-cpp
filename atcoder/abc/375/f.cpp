#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i] -= 1, v[i] -= 1;
    }
    vector<int> init(m, 1);
    vector<array<int, 3>> query(q);
    for (auto &x : query) {
        cin >> x[0];
        if (x[0] == 1) {
            cin >> x[1];
            x[1] -= 1;
            init[x[1]] = 0;
        } else {
            cin >> x[1] >> x[2];
            x[1] -= 1, x[2] -= 1;
        }
    }

    const ll inf = 1e18;
    vector f(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) {
        f[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        if (init[i]) f[u[i]][v[i]] = f[v[i]][u[i]] = w[i];
    }
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][p] + f[p][j]);
            }
        }
    }

    vector<ll> ans;
    for (int i = q - 1; i >= 0; i--) {
        auto &cur = query[i];
        if (cur[0] == 1) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    f[x][y] = min({
                        f[x][y],
                        f[x][u[cur[1]]] + w[cur[1]] + f[v[cur[1]]][y],
                        f[x][v[cur[1]]] + w[cur[1]] + f[u[cur[1]]][y]
                    });
                }
            }
        } else {
            auto dis = f[cur[1]][cur[2]];
            ans.push_back(dis >= inf ? -1 : dis);
        }
    }

    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << "\n";
    }

    return 0;
}

