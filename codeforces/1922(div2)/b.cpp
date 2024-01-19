#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    vector<ll> sum(n + 2);
    for (int i = 0; i <= n; i++) {
        sum[i + 1] = sum[i] + cnt[i];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] >= 2) {
            if (cnt[i] >= 3) ans += 1ll * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            ans += 1ll * cnt[i] * (cnt[i] - 1) / 2 * sum[i];
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
