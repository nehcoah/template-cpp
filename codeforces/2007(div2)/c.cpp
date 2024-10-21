#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int g = gcd(a, b);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i] %= g;
    }
    sort(c.begin(), c.end());
    int ans = c.back() - c[0], mx = 0;
    for (int i = 0; i < n - 1; i++) {
        mx = max(mx, c[i] + g);
        ans = min(ans, mx - c[i + 1]);
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

