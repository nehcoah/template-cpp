//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&](ll x) {
        ll tot = 0;
        for (ll y : a) {
            if (y < x) tot += x - y;
            if (tot > k) return false;
        }
        return true;
    };

    ll l = 0, r = 1e12;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    ll ans = 0;
    for (ll x : a) {
        if (x < l) {
            ans += l;
            k -= l - x;
        } else if (x > l + 1) {
            ans += l + 1;
        } else {
            ans += x;
        }
    }
    ans += k;
    cout << ans - n + 1 << endl;
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
