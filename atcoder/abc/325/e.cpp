#include "bits/stdc++.h"

using namespace std;
using ll = long long;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &g, int start) {
    vector<ll> dist(g.size(), LONG_MAX);
    dist[start] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<ll>> d(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> d[i][j];
    }

    vector<vector<pair<ll, ll>>> adj_car(n), adj_train(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll car = d[i][j] * a;
            ll train = d[i][j] * b + c;
            adj_car[i].emplace_back(j, car);
            adj_car[j].emplace_back(i, car);
            adj_train[i].emplace_back(j, train);
            adj_train[j].emplace_back(i, train);
        }
    }

    auto car = dijkstra(adj_car, 0);
    auto train = dijkstra(adj_train, n - 1);
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, car[i] + train[i]);
    }
    cout << ans << endl;

    return 0;
}

