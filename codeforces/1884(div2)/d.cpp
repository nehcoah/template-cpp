#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> cnt(n + 1);
    vector<int> ban(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
        ban[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            cnt[i] += cnt[j];
            ban[j] |= ban[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 2 * i; j <= n; j += i) {
            cnt[i] -= cnt[j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!ban[i]) ans += cnt[i];
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

