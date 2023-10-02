#include "bits/stdc++.h"

using namespace std;
using ll = long long;


void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = b;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        ans += min(x, a - 1);
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

