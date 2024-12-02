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
    string s;
    cin >> s;

    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        sum += (s[i] - '0') * (i + 1);
        a[i] = sum;
    }
    string ans;
    for (int i = n - 1; i >= 0; i--) {
        ans += char(a[i] % 10 + '0');
        if (i != 0) a[i - 1] += a[i] / 10;
        else {
            auto x = to_string(a[i] / 10);
            while (x.back() == '0') x.pop_back();
            reverse(x.begin(), x.end());
            ans += x;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}

