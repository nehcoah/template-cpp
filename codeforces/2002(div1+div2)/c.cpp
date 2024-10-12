#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    ll dis = 1ll * (xs - xt) * (xs - xt) + 1ll * (ys - yt) * (ys - yt);
    for (int i = 0; i < n; i++) {
        ll cur = 1ll * (x[i] - xt) * (x[i] - xt) + 1ll * (y[i] - yt) * (y[i] - yt);
        if (cur <= dis) {
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

