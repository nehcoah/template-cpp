#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<map<int, ll>> mp(n);
    ll ans = 0;
    auto dfs = [&](auto self, int x, int pa) -> void {
        for (int y : adj[x]) {
            if (y == pa) continue;
            self(self, y, x);
            if (mp[y].contains(c[x])) {
                ans += mp[y][c[x]];
                mp[y].erase(c[x]);
            }
            if (mp[y].size() > mp[x].size()) mp[x].swap(mp[y]);
            for (auto [color, cnt] : mp[y]) {
                ans += 1ll * cnt * mp[x][color];
                mp[x][color] += cnt;
            }
        }
        mp[x][c[x]] += 1;
    };
    dfs(dfs, 0, -1);
    cout << ans << endl;
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
