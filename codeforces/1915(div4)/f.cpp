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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> c(2 * n);
    for (int i = 0; i < n; i++) c[i] = a[i];
    for (int i = 0; i < n; i++) c[i + n] = b[i];
    ranges::sort(c);
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {return b[x] < b[y];});

    Fenwick<int> t(2 * n + 1);
    ll ans = 0;
    for (int i : idx) {
        int l = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        int r = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
        ans += t.query_interval(l, r);
        t.add(l, 1);
    }
    cout << ans << endl;
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

