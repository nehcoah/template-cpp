#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < t; i++) {
        int m; cin >> m;
        for (int _ = 0; _ < m; _++) {
            int x, y; cin >> x >> y;
            x--; y--;
            adj[x].emplace_back(y, i);
            adj[y].emplace_back(x, i);
        }
    }

    int k;
    cin >> k;
    vector<int> a(k);
    vector<vector<int>> pos(t);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]].push_back(i);
    }

    vector<int> dis(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, x] = pq.top(); pq.pop();
        if (dis[x] != -1) continue;
        dis[x] = d;
        for (auto [y, i] : adj[x]) {
            auto it = lower_bound(pos[i].begin(), pos[i].end(), d);
            if (it != pos[i].end()) pq.emplace(*it + 1, y);
        }
    }

    cout << dis[n - 1] << endl;

    return 0;
}

