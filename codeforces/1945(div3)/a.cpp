#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = a + (b + c + 2) / 3;
    if (b % 3 == 1 && c < 2 || b % 3 == 2 && c < 1) cout << -1 << endl;
    else cout << ans << endl;
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
