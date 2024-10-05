#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n && i + j <= x; j++) {
            ans += min((n - i * j) / (i + j), x - i - j);
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

