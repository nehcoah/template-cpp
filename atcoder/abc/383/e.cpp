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

struct UnionFind {
    vector<int> p, a;
    UnionFind(int n, vector<int> a): a(a) {
        p = vector<int>(n, -1);
    }
    int find(int x) {
        if (p[x] < 0) return x;
        else {
            p[x] = find(p[x]);
            return p[x];
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (p[x] < p[y]) {
                swap(x, y);
            }
            a[y] += a[x];
            p[y] += p[x];
            p[x] = y;
        }
    }
    int get(int x) {
        return a[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1, v -= 1;
        e[i] = {w, u, v};
    }
    vector<int> a(k), b(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        b[i] -= 1;
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < k; i++) {
        cnt[a[i]] += 1;
        cnt[b[i]] -= 1;
    }

    sort(e.begin(), e.end());
    UnionFind uf(n, cnt);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        auto [w, u, v] = e[i];
        if (!uf.same(u, v)) {
            ans += 1ll * w * abs(uf.get(u));
            ans += 1ll * w * abs(uf.get(v));
            uf.merge(u, v);
            ans -= 1ll * w * abs(uf.get(u));
        }
    }
    ans /= 2;
    cout << ans << endl;

    return 0;
}

