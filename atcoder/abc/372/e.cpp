#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

struct UnionFind {
    vector<int> f, siz;
    int cnt;

    UnionFind() {}
    UnionFind(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        cnt -= 1;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<set<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[i].insert(i);
    }
    UnionFind uf(n);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int u, v; cin >> u >> v;
            u -= 1, v -= 1;
            int x = uf.find(u), y = uf.find(v);
            if (uf.merge(u, v)) {
                int z = uf.find(u);
                for (int p : adj[x]) adj[z].insert(p);
                for (int p : adj[y]) adj[z].insert(p);
                while (adj[z].size() > 10) adj[z].erase(adj[z].begin());
            }
        } else {
            int v, k;
            cin >> v >> k;
            v -= 1;
            v = uf.find(v);
            if (adj[v].size() < k) {
                cout << -1 << "\n";
                continue;
            }
            auto it = adj[v].rbegin();
            for (int i = 1; i < k; i++, it++) {}
            cout << *it + 1 << "\n";
        }
    }

    return 0;
}

