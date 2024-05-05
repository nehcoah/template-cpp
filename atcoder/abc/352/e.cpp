//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m;
    vector<int> c(m);
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> k >> c[i];
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][j] -= 1;
        }
    }

    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return c[i] < c[j];
    });

    UnionFind uf(n);
    ll ans = 0;
    for (int i : idx) {
        int w = c[i], pre = -1;
        for (int x : a[i]) {
            if (pre == -1) pre = x;
            else if (uf.merge(pre, x)) ans += w;
        }
        if (uf.cnt == 1) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
