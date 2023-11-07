#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<array<ll, 3>>> adj(n);
    for (int i = 0; i < m; i++) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        adj[a].push_back({b, x, y});
        adj[b].push_back({a, -x, -y});
    }

    vector<bool> vis(n);
    vector<pair<ll, ll>> idx(n);
    auto dfs = [&](auto self, int cur, ll x, ll y) -> void {
        for (auto [nxt, dx, dy] : adj[cur]) {
            if (vis[nxt]) continue;
            idx[nxt] = {x + dx, y + dy};
            vis[nxt] = 1;
            self(self, nxt, x + dx, y + dy);
        }
    };
    vis[0] = 1;
    dfs(dfs, 0, 0, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) cout << "undecidable" << endl;
        else cout << idx[i].first << " " << idx[i].second << endl;
    }


    return 0;
}
