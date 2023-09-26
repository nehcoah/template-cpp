#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            a[i] |= 1LL << x;
        }
        sum |= a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 50; i++) {
        if (sum >> i & 1) {
            ll cur = 0;
            for (int j = 0; j < n; j++) {
                if ((a[j] >> i & 1) == 0) cur |= a[j];
            }
            ans = max(ans, __builtin_popcountll(cur));
        }
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
