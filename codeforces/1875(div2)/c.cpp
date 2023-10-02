#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    n %= m;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    double t = 1.0 * n / m;
    ll ans = 0, cnt = 1;
    bool f = false;
    for (ll i = 0, j = 2; i < 32; i++, j *= 2) {
        t *= 2;
        if (t >= 1) {
            ans += (m / j) * cnt;
            t -= 1;
            if (t == 0) {
                f = true;
                break;
            }
        }
        cnt += j;
    }

    if (f) cout << ans << endl;
    else cout << -1 << endl;
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

