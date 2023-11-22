// 32

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 2e5 + 50;
    const int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;

    vector<vector<array<ll, 3>>> adj(n + m), nadj(n + m);
    for (int i = 0; i < m; i++) {
        int l1, r1, l2, r2, a, b;
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        l1--, r1--, l2--, r2--;
        for (int k = l1; k <= r1; k++) {
            adj[k].push_back({n + i, a, b});
            nadj[n + i].push_back({k, a, b});
        }
        for (int k = l2; k <= r2; k++) {
            adj[n + i].push_back({k, a, b});
            nadj[k].push_back({n + i, a, b});
        }
    }

    auto dijkstra = [&](vector<vector<array<ll, 3>>>& g) {
        vector<ll> dis(n + m, 1e18);
        priority_queue<pair<ll, ll>> pq;
        dis[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ll d = -cur.first, x = cur.second;
            if (d > dis[x]) continue;
            for (auto &nxt : g[x]) {
                ll y = nxt[0], wt = nxt[1];
                if (dis[x] + wt >= dis[y]) continue;
                dis[y] = dis[x] + wt;
                pq.emplace(-dis[y], y);
            }
        }
        return dis;
    };

    auto dis1 = dijkstra(adj);
    auto dis2 = dijkstra(nadj);
    for (int i = 1; i < n; i++) {
        if (dis1[i] == 1e18 || dis2[i] == 1e18) cout << -1 << " \n"[i == n - 1];
        else cout << (dis1[i] + dis2[i]) / 2 % mod << " \n"[i == n - 1];
    }

    return 0;
}


