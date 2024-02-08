#include "bits/stdc++.h"

using namespace std;
using ll = long long;

struct UnionFind {
    vector<int> parent, size;
    int cnt;

    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        cnt = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        --cnt;
        return true;
    }

    bool is_connected(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[0] > b[0];
    });
    UnionFind uf(n);
    vector<vector<int>> adj(n);
    int ans = 1e9, st, ed;
    for (auto [w, u, v] : edges) {
        if (!uf.merge(u, v)) {
            ans = w;
            st = u, ed = v;
        } else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<int> r;
    auto dfs = [&](auto self, int x, int pa) {
        if (x == ed) {
            return true;
        }
        for (int y : adj[x]) {
            if (y == pa) continue;
            if (self(self, y, x)) {
                r.push_back(y);
                return true;
            }
        }
        return false;
    };
    dfs(dfs, st, -1);
    cout << ans << " " << r.size() + 1 << endl;
    for (int x : r) {
        cout << x + 1 << " ";
    }
    cout << st + 1 << endl;
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
