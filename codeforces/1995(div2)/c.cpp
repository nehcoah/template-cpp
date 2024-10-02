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
    int p = 0;
    while (p < n && a[p] == 1) p += 1;
    ll ans = 0, pre = 0;
    for (int i = p + 1; i < n; i++) {
        if (a[i] == 1) {
            cout << -1 << "\n";
            return;
        }
        ll x = a[i], cur = 0;
        while (x < a[i - 1]) {
            x *= x;
            cur += 1;
        }
        x = a[i - 1];
        while (pre && x * x <= a[i]) {
            x *= x;
            pre -= 1;
        }
        ans += cur + pre;
        pre = cur + pre;
    }
    cout << ans << "\n";
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

