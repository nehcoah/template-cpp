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

    int n;
    cin >> n;
    int ans = 0;
    vector<int> t(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) ans = max(0, ans - t[i] + t[i - 1]);
        ans += v[i];
    }
    cout << ans << endl;

    return 0;
}

