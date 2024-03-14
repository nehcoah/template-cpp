#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<map<int, vector<int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }

    int s, e;
    cin >> s >> e;
    s--, e--;

    map<pair<int, int>, int> dis;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.emplace(0, s, 0);
    while (!pq.empty()) {
        auto [d, x, c] = pq.top(); pq.pop();
        if (dis.count({x, c})) continue;
        dis[{x, c}] = d;
        if (c) {
            pq.emplace(d, x, 0);
            for (int y : adj[x][c]) {
                pq.emplace(d, y, c);
            }
        } else {
            for (auto &[_c, _] : adj[x]) {
                pq.emplace(d + 1, x, _c);
            }
        }
    }

    cout << dis[{e, 0}] << endl;
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
