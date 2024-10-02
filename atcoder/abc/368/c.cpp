#include "bits/stdc++.h"
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (ll x : a) {
        ll t = x / 5;
        ll m = x % 5;
        ll p = ans % 3;    // 0 -> 1 1 3, 1 -> 1 3 1, 2 -> 3 1 1
        if (p == 0) ans += 3 * t + (m <= 2 ? m : 3);
        else if (p == 1) ans += 3 * t + (m <= 1 ? m : 2);
        else ans += 3 * t + (m == 0 ? 0 : max(1ll, m - 2));
    }
    cout << ans << endl;

    return 0;
}

