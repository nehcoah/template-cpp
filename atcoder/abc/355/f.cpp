#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    int n, q;
    cin >> n >> q;
    vector<UnionFind> uf(10, UnionFind(n));
    vector<int> cnt(10, n);

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        for (int j = w; j <= 10; j++) {
            cnt[j - 1] -= uf[j - 1].merge(u, v);
        }
    }

    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        for (int j = w; j <= 10; j++) {
            cnt[j - 1] -= uf[j - 1].merge(u, v);
        }
        int ans = 0, pre = n;
        for (int j = 1; j <= 10; j++) {
            ans += j * (pre - cnt[j - 1]);
            pre = cnt[j - 1];
        }
        cout << ans << endl;
    }


    return 0;
}
