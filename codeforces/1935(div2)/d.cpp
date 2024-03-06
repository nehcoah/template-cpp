#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ll ans = 0, odd = 0, even = 0;
    sort(s.begin(), s.end());
    for (int x : s) {
        ans += c - x + 1;
        ans += x / 2 - (x & 1 ? odd : even);
        (x & 1 ? odd : even) += 1;
    }
    cout << 1ll * (c + 1) * (c + 2) / 2 - ans << "\n";
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
