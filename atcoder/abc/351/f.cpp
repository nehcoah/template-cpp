//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto id = a;
    sort(id.begin(), id.end());

    Fenwick<int> cnt(n);
    Fenwick<ll> sum(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = lower_bound(id.begin(), id.end(), a[i]) - id.begin();
        ans += 1ll * a[i] * cnt.query(x - 1) - sum.query(x - 1);
        cnt.add(x, 1);
        sum.add(x, a[i]);
    }
    cout << ans << endl;

    return 0;
}
