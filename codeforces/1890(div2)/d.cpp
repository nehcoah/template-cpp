#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    vector<int> vis(n, 0);
    for (int i = 1; i < n; i++) {
        if (a[0] + a[i] >= (ll)(i + 1) * c) {
            sum += a[i];
            vis[i] = 1;
            vis[0] = 1;
        }
    }
    if (vis[0] == 0) {
        cout << "No" << endl;
        return;
    }
    sum += a[0];
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    ranges::sort(idx, [&](int x, int y) {
        ll fx = (ll)(x + 1) * c - a[x];
        ll fy = (ll)(y + 1) * c - a[y];
        return fx < fy;
    });
    for (int i : idx) {
        if (vis[i]) continue;
        sum += a[i];
        if (sum < (ll)(i + 1) * c) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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

