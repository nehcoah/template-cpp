#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) adj[a[i]].push_back(i);

    vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
        if (vis[i] == -1) {
            int x = i;
            while (vis[x] == -1) {
                vis[x] = 1;
                x = a[x];
            }
            bool ok = false;
            for (int z = 0; z < 2; z++) {
                bool f = true;
                auto dfs = [&](auto self, int y, bool seen = false) -> void {
                    if (y == x && !seen) {
                        vis[y] = z;
                        return;
                    }
                    int std = 1;
                    for (int nxt : adj[y]) {
                        self(self, nxt);
                        if (vis[nxt]) std = 0;
                    }
                    if (seen && vis[y] != std) {
                        f = false;
                        return;
                    }
                    vis[y] = std;
                };
                dfs(dfs, x, true);
                if (f) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) ans.push_back(a[i]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " \n"[i == ans.size() - 1];

    return 0;
}

