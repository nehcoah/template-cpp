#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (a == b) {
        cout << "NO" << endl;
        return;
    }
    vector<int> vis(n);
    int f = -1;
    unordered_set<int> st;
    auto dfs = [&](auto self, int x, int pa) {
        for (int y : adj[x]) {
            if (y == pa) continue;
            if (vis[y]) {
                f = y;
                st.insert(x);
                return;
            }
            vis[x] = 1;
            self(self, y, x);
            if (f != -1) break;
        }
        if (f != -1) {
            st.insert(x);
            if (f == x) f = -1;
        }
    };
    vis[0] = 1;
    dfs(dfs, 0, -1);

    if (st.count(b)) {
        cout << "YES" << endl;
        return;
    }

    vis.assign(n, 0);
    queue<tuple<int, int, int>> q;
    q.emplace(b, -1, 0);
    vis[b] = 1;
    int d, node;
    while (!q.empty()) {
        auto [x, pa, dis] = q.front(); q.pop();
        if (st.count(x)) {
            node = x;
            d = dis;
            break;
        }
        for (int y : adj[x]) {
            if (y == pa || vis[y]) continue;
            vis[y] = 1;
            q.emplace(y, x, dis + 1);
        }
    }
    while (!q.empty()) q.pop();
    vis.assign(n, 0);
    q.emplace(a, -1, 0);
    while (!q.empty()) {
        auto [x, pa, dis] = q.front(); q.pop();
        if (x == node) {
            if (dis <= d) cout << "NO" << endl;
            else cout << "YES" << endl;
            return;
        }
        for (int y : adj[x]) {
            if (y == pa || vis[y]) continue;
            vis[y] = 1;
            q.emplace(y, x, dis + 1);
        }
    }
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
