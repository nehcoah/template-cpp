#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll x = 1;
    for (int i = 0; i < n; i++) {
        x = lcm(x, 1ll * a[i]);
        if (x > 1e9) break;
    }
    if (find(a.begin(), a.end(), x) == a.end()) {
        cout << n << endl;
        return;
    }
    auto check = [&](ll t) -> int {
        if (find(a.begin(), a.end(), t) != a.end()) {
            return 0;
        }
        ll x = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t % a[i] == 0) {
                x = lcm(x, a[i]);
                cnt += 1;
            }
        }
        return x == t ? cnt : 0;
    };
    int ans = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ans = max(ans, check(i));
            ans = max(ans, check(x / i));
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
