#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }
    vector<int> sz(n);
    auto get_sz = [&](auto self, int x) -> int {
        sz[x] = 1;
        for (int y : adj[x]) {
            sz[x] += self(self, y);
        }
        return sz[x];
    };
    get_sz(get_sz, 0);

    auto dfs = [&](auto self, int x) -> int {
        int mx = 0;
        for (int y : adj[x]) {
            mx = max(mx, sz[y]);
        }
        if (mx * 2 > sz[x] - 1) {
            for (int y : adj[x]) {
                if (sz[y] == mx) {
                    int z = self(self, y);
                    return z + min((sz[x] - 1 - 2 * z) / 2, sz[x] - 1 - sz[y]);
                }
            }
        } else {
            return (sz[x] - 1) / 2;
        }
    };
    cout << dfs(dfs, 0) << endl;
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

