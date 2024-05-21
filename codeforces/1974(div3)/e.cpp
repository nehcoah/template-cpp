#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int m, x;
    cin >> m >> x;
    vector<int> c(m), h(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> h[i];
    }

    int sum = accumulate(h.begin(), h.end(), 0);
    vector<ll> f(sum + 1, 1e18);
    f[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = sum; j >= h[i]; j--) {
            ll w = f[j - h[i]] + c[i];
            if (w > 1ll * i * x) continue;
            f[j] = min(f[j], w);
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        if (f[i] < 1e18) ans = i;
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
