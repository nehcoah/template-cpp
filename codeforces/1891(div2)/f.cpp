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

    void update(int pos, T val) {
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
        return query(r) - query(l - 1);
    }

};

void solve() {
    int q, tot = 1;
    cin >> q;
    vector<vector<int>> adj(q + 1);
    vector<vector<pair<int, int>>> op(q + 1);
    for (int i = 0; i < q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int v; cin >> v;
            v--;
            adj[v].push_back(tot++);
        } else {
            int v, x;
            cin >> v >> x;
            v--;
            op[v].emplace_back(tot, x);
        }
    }

    vector<ll> ans(tot);
    Fenwick<ll> f(tot + 1);
    auto dfs = [&](auto self, int y) -> void {
        for (auto [cur, x] : op[y]) f.update(tot - cur + 1, x);
        ans[y] = f.query(tot - y);
        for (int z : adj[y]) self(self, z);
        for (auto [cur, x] : op[y]) f.update(tot - cur + 1, -x);
    };
    dfs(dfs, 0);

    for (int i = 0; i < tot; i++) cout << ans[i] << " \n"[i == tot - 1];
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

