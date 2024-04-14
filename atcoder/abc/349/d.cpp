// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l, r;
    cin >> l >> r;
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < 60 && l < r; i++) {
        if (l >> i & 1) {
            ll p = l;
            if (l + (1ll << i) > r) break;
            l += 1ll << i;
            ans.emplace_back(p, l);
        }
    }
    for (int i = 60; i >= 0; i--) {
        if (r >> i & 1 && (l >> i & 1) == 0) {
            ll p = l;
            l += 1ll << i;
            ans.emplace_back(p, l);
            if (l == r) break;
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans) {
        cout << x << " " << y << endl;
    }

    return 0;
}
