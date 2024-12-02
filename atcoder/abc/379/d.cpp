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

    int q;
    cin >> q;

    ll cur = 1e18;
    deque<ll> dq;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            dq.push_front(cur);
        } else if (op == 2) {
            int t; cin >> t;
            cur -= t;
        } else {
            int h; cin >> h;
            auto x = lower_bound(dq.begin(), dq.end(), cur + h) - dq.begin();
            cout << dq.size() - x << "\n";
            dq.resize(x);
        }
    }

    return 0;
}

