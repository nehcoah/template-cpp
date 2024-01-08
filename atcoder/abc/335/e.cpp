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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<int> a(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (a[u] == a[v]) uf.merge(u, v);
        else {
            if (a[u] > a[v]) swap(u, v);
            adj[u].push_back(v);
        }
    }

    vector<int> idx(n), f(n, numeric_limits<int>::min());
    f[uf.find(0)] = 1;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {return a[x] < a[y];});
    for (int x : idx) {
        for (int y : adj[x]) {
            f[uf.find(y)] = max(f[uf.find(y)], f[uf.find(x)] + 1);
        }
    }
    cout << max(0, f[uf.find(n - 1)]) << endl;

    return 0;
}

