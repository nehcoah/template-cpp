#include "bits/stdc++.h"

using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cin >> adj[i][i + j + 1];
            adj[i + j + 1][i] = adj[i][i + j + 1];
        }
    }

    vector<ll> f(1 << n, -1);
    auto dfs = [&](auto self, int mask) -> ll  {
        if (mask == (1 << n) - 1) return 0;
        if (f[mask] != -1) return f[mask];
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) continue;
            for (int j = i + 1; j < n; j++) {
                if (mask >> j & 1) continue;
                ans = max(ans, self(self, mask | (1 << i) | (1 << j)) + adj[i][j]);
            }
        }
        return f[mask] = ans;
    };
    ll ans = dfs(dfs, 0);
    cout << ans << endl;

    return 0;
}

