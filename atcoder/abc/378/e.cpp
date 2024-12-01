#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

//template <typename K, typename V, typename Comp = std::less<K>>
//using ordered_map = __gnu_pbds::tree<
//        K, V, Comp,
//        __gnu_pbds::rb_tree_tag,
//        __gnu_pbds::tree_order_statistics_node_update
//>;
//
//template <typename K, typename Comp = std::less<K>>
//using ordered_set = ordered_map<K, __gnu_pbds::null_type, Comp>;


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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = (sum[i] + a[i]) % m;
    }

    ll ans = 0, pre = 0;
    Fenwick<int> t(m + 1);
    for (int i = 0; i <= n; i++) {
        ans += sum[i] * i - pre;
        pre += sum[i];
        ans += 1ll * t.query_interval(sum[i] + 1, m) * m;
        t.add(sum[i], 1);
    }
    cout << ans << endl;

    return 0;
}

