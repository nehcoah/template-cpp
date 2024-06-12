#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        if (k % i != 0) continue;
        for (int j = 1; j <= y; j++) {
            if (k / i % j != 0) continue;
            ll cur = (x - i + 1) * (y - j + 1) * (z - k / i / j + 1);
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
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

