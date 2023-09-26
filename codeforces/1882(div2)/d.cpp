#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> ans(n), size(n);
    auto dfs = [&](auto self, int x, int pa)-> int {
        int cur = 1;
        for (int y : adj[x]) {
            if (y == pa) continue;
            int sz = self(self, y, x);
            ans[0] += (ll)sz * (a[x] ^ a[y]);
            cur += sz;
        }
        return size[x] = cur;
    };
    dfs(dfs, 0, -1);

    auto reroot = [&](auto self, int x, int pa) -> void {
        for (int y : adj[x]) {
            if (y == pa) continue;
            int c = a[x] ^ a[y];
            ans[y] = ans[x] + (ll)c * (n - size[y]) - (ll)c * size[y];
            self(self, y, x);
        }
    };
    reroot(reroot, 0, -1);

    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
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
