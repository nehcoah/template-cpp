#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int h, n;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    auto check = [&](ll x) {
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1ll * a[i] * (x / c[i] + 1);
            if (sum >= h) return true;
        }
        return sum >= h;
    };

    ll l = 0, r = 1e12;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l + 1 << endl;
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

