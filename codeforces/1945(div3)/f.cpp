#include "bits/stdc++.h"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n), p(n);
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> t;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        t.insert({v[i], i});
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if ((int) t.size() - i - 1 < 0) break;
        ll cur = max(ans, 1ll * (i + 1) * (*t.find_by_order(t.size() - i - 1)).first);
        if (cur > ans) {
            ans = cur, cnt = i + 1;
        }
        t.erase({v[p[i] - 1], p[i] - 1});
    }
    cout << ans << " " << cnt << endl;
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
