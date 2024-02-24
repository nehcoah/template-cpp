#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), x(n);
    vector<ll> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i] = abs(x[i]);
        cnt[x[i]] += a[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += cnt[i];
        if (1ll * k * i < sum) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
