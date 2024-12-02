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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(m), a(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    if (accumulate(a.begin(), a.end(), 0ll) != n) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {
        return x[i] < x[j];
    });

    ll ans = 0, hold = 0;
    for (int i = 0; i < p.size(); i++) {
        int id = p[i];
        if (i == 0) {
            if (x[id] != 1) {
                cout << -1 << endl;
                return 0;
            }
            hold = a[id] - 1;
        } else {
            if (x[id] - x[p[i - 1]] - 1 > hold) {
                cout << -1 << endl;
                return 0;
            }
            int y = x[id] - x[p[i - 1]] - 1;
            ans += 1ll * (1 + y) * y / 2 + 1ll * (hold - y) * (x[id] - x[p[i - 1]]);
            hold -= y;
            hold += a[id] - 1;
        }
    }
    int y = n - x[p.back()];
    ans += 1ll * (1 + y) * y / 2;
    cout << ans << endl;

    return 0;
}

