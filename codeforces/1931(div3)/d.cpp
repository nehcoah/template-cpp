#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        int c = a[i];
        auto p = make_pair(c % x == 0 ? 0 : x - c % x, c % y);
        ans += mp[p];
        mp[{c % x, c % y}] += 1;
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

