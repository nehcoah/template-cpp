#include "bits/stdc++.h"

using namespace std;
using ll = long long;


template<typename T>
struct Fenwick {
    int n;
    vector<T> tree;

    Fenwick(int n = 0) {
        init(n);
    }

    void init(int sz) {
        this->n = sz + 1;
        tree.assign(sz + 2, T());
    }

    void clear() {
        tree.assign(n + 2, T());
    }

    void add(int pos, T val) {
        pos++;
        for (; pos < tree.size(); pos += pos & -pos) tree[pos] += val;
    }

    T query(int pos) {
        pos++;
        auto ans = T();
        for (; pos; pos -= pos & -pos) ans += tree[pos];
        return ans;
    }

    T query_interval(int l, int r) {
        assert(l <= r);
        return query(r) - query(l - 1);
    }

};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> p(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i] - 1] = i;
    }

    vector<vector<array<int, 3>>> query(n);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--; x--;
        query[x].push_back({l, r, i});
    }

    vector<int> ans(q);
    Fenwick<int> t(n + 1);
    auto dfs = [&](auto self, int u, int pa) -> void {
        for (auto [l, r, i] : query[u]) ans[i] -= t.query_interval(l, r);
        t.add(pos[u], 1);
        for (int v : adj[u]) {
            if (v == pa) continue;
            self(self, v, u);
        }
        for (auto [l, r, i] : query[u]) ans[i] += t.query_interval(l, r);
    };
    dfs(dfs, 0, -1);

    for (int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << "\n";
    cout << "\n";
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


