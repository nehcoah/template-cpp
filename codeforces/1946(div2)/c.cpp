#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sz(n, 1);
    auto dfs = [&](auto self, int x, int pa) -> void {
        for (int y : adj[x]) {
            if (y == pa) continue;
            self(self, y, x);
            sz[x] += sz[y];
        }
    };
    dfs(dfs, 0, -1);
//    for (int i = 0; i < n; i++) cout << sz[i] << " ";
//    cout << endl;

    auto check = [&](int t) {
        int cnt = 0;
        auto reroot = [&](auto self, int x, int pa) -> int {
            int pre = 0;
            for (int y : adj[x]) {
                if (y == pa) continue;
                pre += self(self, y, x);
            }
            if (sz[x] - pre >= t) {
                cnt += 1;
                pre = sz[x];
            }
            return pre;
        };
        reroot(reroot, 0, -1);
//        cout << t << " " << cnt << " " << last << endl;
        return cnt > k;
    };

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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
