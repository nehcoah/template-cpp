#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> ind(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, -w);
    }

    vector<int> vis(n);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        queue<pair<ll, int>> q;
        q.emplace(0, i);
        while (!q.empty()) {
            auto [d, x] = q.front(); q.pop();
            vis[x] = 1;
            ans[x] = d;
            for (auto [y, w] : adj[x]) {
                if (vis[y]) continue;
                q.emplace(d + w, y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }


    return 0;
}

