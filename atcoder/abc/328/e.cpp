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

    bool merge(int x, int y){
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
    ll k;
    cin >> n >> m >> k;
    vector<array<ll, 3>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u, v, w});
    }
    vector<int> mask(m);
    for (int i = 0; i < n - 1; i++) mask[i] = 1;
    vector<int> a = mask;
    ll ans = 1e16;
    do {
        int cur = 0;
        ll sum = 0;
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            if (mask[i] == 1) {
                uf.merge(edges[i][0], edges[i][1]);
                sum += edges[i][2];
            }
        }
        if (uf.cnt == 1) {
            ans = min(ans, sum % k);
        }
        next_permutation(mask.begin(), mask.end());
    } while (a != mask);

    cout << ans << endl;

    return 0;
}

