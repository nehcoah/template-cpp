#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    ll c = 0, m = 1;

    while (true) {
        ll cur = (n + m) / (2 * m);
        if (c + cur >= k) {
            ll ans = 2 * m * (k - c) - m;
            cout << ans << endl;
            return;
        }
        c += cur;
        m *= 2;
    }
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
