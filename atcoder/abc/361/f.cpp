#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    const ll mx = 1e6;
    ll ans = 0;
    vector<int> vis(mx + 1);
    vector<int> st;
    for (int i = 2; i <= min(mx, n); i++) {
        if (vis[i]) continue;
        for (__int128 x = 1ll * i * i; x <= n; x *= i) {
            ans += 1;
            if (x <= mx) vis[x] = 1;
            if (x > mx && x <= min(n, (ll) 1e9)) st.push_back(x);
        }
    }
    sort(st.begin(), st.end());
    if (n > (ll) 1e12) {
        ll l = 1e6 + 1, r = 1e9;
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (mid * mid <= n) l = mid;
            else r = mid - 1;
        }
        ans += l - 1e6;
        auto p = upper_bound(st.begin(), st.end(), l) - st.begin();
        ans -= p;
    }
    cout << ans + 1 << endl;

    return 0;
}
