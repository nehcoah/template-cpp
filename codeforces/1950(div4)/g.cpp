#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i] >> w[i];
    }
    vector adj(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = adj[j][i] = g[i] == g[j] || w[i] == w[j];
        }
    }

    vector dp(n + 1, vector<int>(1 << n, -1));
    auto dfs = [&](auto self, int pre, int mask) -> int {
        int ans = 0;
        if (dp[pre][mask] != -1) return dp[pre][mask];
        for (int x = 0; x < n; x++) {
            if (mask >> x & 1) continue;
            if (pre == n || adj[pre][x]) ans = max(ans, self(self, x, mask | 1 << x) + 1);
        }
        return dp[pre][mask] = ans;
    };
    cout << n - dfs(dfs, n, 0) << endl;
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
