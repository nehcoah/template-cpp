#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    map<ll, array<int, 4>> mp;
    for (int i = 0; i < m; i++) {
        int l, d, k, c, a, b;
        cin >> l >> d >> k >> c >> a >> b;
        a--, b--;
        mp[1ll * b << 32 | a] = {l, d, k, c};
        adj[b].push_back(a);
    }

    auto dijkstra = [&]() {
        vector<long long> dist(n, -1);
        priority_queue<pair<long long, int>> pq;
        dist.back() = numeric_limits<ll>::max();
        for (int y : adj[n - 1]) {
            ll info = 1ll * (n - 1) << 32 | y;
            auto [l, d, k, c] = mp[info];
            dist[y] = max(dist[y], 1ll * (k - 1) * d + l);
        }
        for (int i = 0; i < n - 1; i++) {
            if (dist[i] != -1) pq.emplace(dist[i], i);
        }
        while (!pq.empty()) {
            auto[dis, x] = pq.top();
            pq.pop();
            if (dis < dist[x]) continue;
            for (int y : adj[x]) {
                ll info = 1ll * x << 32 | y;
                auto [l, d, k, c] = mp[info];
                ll new_d = dist[x] - c;
                if (new_d >= l) {
                    ll mod = (new_d - l) % d;
                    new_d -= mod;
                    new_d = min(new_d, 1ll * (k - 1) * d + l);
                    if (new_d > dist[y]) {
                        dist[y] = new_d;
                        pq.emplace(new_d, y);
                    }
                }
            }
        }
        return dist;
    };

    auto ans = dijkstra();

    for (int i = 0; i < n - 1; i++) {
        if (ans[i] == -1) cout << "Unreachable\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}
