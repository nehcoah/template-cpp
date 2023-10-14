#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(16);

    int n, m;
    cin >> n >> m;
    vector<array<int, 4>> adj(m);
    for (int i = 0; i < m; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        u--; v--;
        adj.push_back({u, v, b, c});
    }
    sort(adj.begin(), adj.end());

    double l = 0, r = 1e5;
    for (int i = 0; i < 100; i++) {
        auto mid = (l + r) / 2;
        vector<double> f(n, -1e9);
        f[0] = 0;
        for (auto [u, v, b, c] : adj) {
            f[v] = max(f[v], f[u] + b - c * mid);
        }
        if (f[n - 1] >= 0) l = mid;
        else r = mid;
    }

    cout << l << endl;

    return 0;
}

