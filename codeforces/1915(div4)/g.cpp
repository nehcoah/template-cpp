#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    auto dijkstra = [&](vector<vector<pair<int, ll>>> &g, int start, bool b = true) {
        vector<ll> dis(n, numeric_limits<ll>::max());
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        pq.emplace(0, start);
        dis[start] = 0;
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d > dis[x]) continue;
            for (auto [y, w] : g[x]) {
                if (dis[y] > dis[x] + w * (b ? 1 : s[x])) {
                    dis[y] = dis[x] + w * (b ? 1 : s[x]);
                    pq.emplace(dis[x] + w * (b ? 1 : s[x]), y);
                }
            }
        }
        return dis;
    };
    
    vector<vector<pair<int, ll>>> n_adj(n);
    for (int i = 0; i < n; i++) {
        auto d = dijkstra(adj, i);
        for (int j = 0; j < n; j++) {
            n_adj[i].emplace_back(j, d[j]);
        }
    }

    cout << dijkstra(n_adj, 0, false)[n - 1] << endl;
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

