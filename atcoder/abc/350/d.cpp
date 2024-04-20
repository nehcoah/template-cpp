// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<int> t;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            t.push_back(x);
            for (int y : adj[x]) {
                if (!vis[y]) q.push(y), vis[y] = 1;
            }
        }
        int cnt = t.size(), e = 0;
        for (int x : t) {
            e += adj[x].size();
        }
        e /= 2;
        ans += 1ll * cnt * (cnt - 1) / 2 - e;
    }
    cout << ans << endl;

    return 0;
}
