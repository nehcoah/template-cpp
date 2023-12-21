#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::sort(p, [&](int x, int y) {
        return a[x] + b[x] > a[y] + b[y];
    });
    for (int i = 0; i < n; i++) {
        if (i & 1) ans -= b[p[i]] - 1;
        else ans += a[p[i]] - 1;
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

