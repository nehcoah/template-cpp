#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    auto check = [&](int r) {
        ll ans = 0;
        for (int x = 1; x <= r; x++) {
            ll s = 1ll * r * r - 1ll * x * x;
            ll t = sqrt(s);
            if (t * t == s) {
                ans += 2 * (t - 1) + 1;
            } else {
                ans += 2 * t + 1;
            }
        }
        ans = ans * 2 + r * 2 - 1;
        return ans;
    };
    int r;
    cin >> r;
    cout << check(r + 1) - check(r) << endl;
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
