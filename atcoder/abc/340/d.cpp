#include "bits/stdc++.h"

using namespace std;
using ll = long long;

vector<long long> dijkstra(vector<vector<pair<int, long long>>> &g, int start) {
    vector<long long> dist(g.size(), 1e18);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto[d, x] = pq.top();
        pq.pop();
        if (d > dist[x]) continue;
        for (auto& [y, wt] : g[x]) {
            ll new_d = dist[x] + wt;
            if (new_d < dist[y]) {
                dist[y] = new_d;
                pq.emplace(new_d, y);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, ll>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[i].emplace_back(i + 1, a);
        adj[i].emplace_back(x - 1, b);
    }

    auto d = dijkstra(adj, 0);
    cout << d.back() << endl;

    return 0;
}
