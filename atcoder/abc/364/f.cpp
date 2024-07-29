#include "bits/stdc++.h"
using namespace std;

using ll = long long;

struct DSU {
    vector<int> f, siz;
    int cnt;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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
    vector<int> l(q), r(q), c(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i] >> c[i];
        l[i] -= 1, r[i] -= 1;
    }

    vector<int> idx(q);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return c[i] < c[j];
    });
    ll ans = 0;
    DSU uf(n);
    for (int i : idx) {
        ans += c[i];
        for (int x = uf.find(l[i]); x + 1 <= r[i]; x = uf.find(x)) {
            uf.merge(x + 1, x);
            ans += c[i];
        }
    }

    if (uf.cnt == 1) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
