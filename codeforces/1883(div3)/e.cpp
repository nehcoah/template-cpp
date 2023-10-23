#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, cur = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ll x = a[i];
            while (x < a[i - 1]) {
                cur++;
                x *= 2;
            }
        } else {
            ll x = a[i - 1];
            while (x * 2 <= a[i] && cur) {
                x *= 2;
                cur--;
            }
        }
        ans += cur;
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

