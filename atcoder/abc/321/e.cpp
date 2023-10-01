#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;

__int128 pow_(__int128 a, long long b) {
    __int128 ans = 1;
    for (; b; b /= 2) {
        if (b % 2) ans = ans * a;
        a = a * a;
    }
    return ans;
}

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;

    auto check = [&](ll xx, ll kk) {
        if (int(log2(n / xx)) < kk) return __int128(0);
        __int128 s = pow_(2, kk) * xx;
        return s != -1 && s <= n ? min(n - s + 1, pow_(2, kk)) : 0;
    };

    ll ans = check(x, k);
    for (; x > 1 && k; x /= 2, k--) {
        if (k < 2) {
            ans += 1;
            continue;
        }
        if (x % 2 == 1) ans += check(x - 1, k - 2);
        else ans += check(x + 1, k - 2);
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
