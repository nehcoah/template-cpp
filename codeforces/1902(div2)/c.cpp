#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ranges::sort(a);
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    ll d = a[1] - a[0];
    for (int i = 0; i < n - 1; i++) {
        d = min(d, gcd(d, a[i + 1] - a[i]));
    }
    ll x = a.back(), ans = 0;
    for (int y : a) {
        ans += (x - y) / d;
    }
    ll x1 = n, x2 = n + 1;
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        if (a[i] != a.back() - j * d) {
            x2 = j;
            break;
        }
    }
    cout << ans + min(x1, x2) << endl;
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

