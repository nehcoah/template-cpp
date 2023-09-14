//
// Created by Nehcoah on 2023/9/14.
//

#include <vector>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, long long>>> &g, int start) {
    vector<long long> dist(g.size(), 1e18 + 1), cnt(g.size());
    dist[start] = 0;
    cnt[0] = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto[d, x] = pq.top();
        pq.pop();
        if (d > dist[x]) continue;
        for (auto& [y, wt] : g[x]) {
            int new_d = dist[x] + wt;
            if (new_d < dist[y]) {
                dist[y] = new_d;
                pq.emplace(new_d, y);
                cnt[y] = cnt[x];
            } else if (new_d == dist[y]) cnt[y] += cnt[x];
        }
    }
    return dist;
}

vector<long long> dijkstra(vector<vector<long long>> &g, int start) {
    int n = g.size();
    vector<long long> dist(n, 1e18 + 1), vis(n);
    dist[start] = 0;
    for (;;) {
        int x = -1;
        for (int i = 0; i < n; ++i)
            if (!vis[i] && (x < 0 || dist[i] < dist[x]))
                x = i;
        if (x == -1) break;
        vis[x] = true;
        for (int y = 0; y < n; ++y) dist[y] = min(dist[y], dist[x] + g[x][y]);
    }
    return dist;
}

vector<vector<long long>> floyd(vector<vector<long long>> w, int n) {
    for (int p = 0; p < n; p++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                w[i][j] = min(w[i][j], w[i][p] + w[p][j]);
            }
        }
    }
    return w;
}