#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    vector<ll> dis(n, -1);
    pq.emplace(a[0], 0);
    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop();
        if (dis[x] != -1) continue;
        dis[x] = d;
        for (auto [y, w] : adj[x]) {
            pq.emplace(d + w + a[y], y);
        }
    }
    for (int i = 1; i < n; i++) {
        cout << dis[i] << " \n"[i == n - 1];
    }

    return 0;
}
