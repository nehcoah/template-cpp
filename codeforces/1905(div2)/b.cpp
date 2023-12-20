#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto self, int x, int pa) -> void {
        if (adj[x].size() == 1) ans++;
        for (int y : adj[x]) {
            if (y == pa) continue;
            self(self, y, x);
        }
    };
    dfs(dfs, 0, -1);
    cout << (ans + 1) / 2 << endl;
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

