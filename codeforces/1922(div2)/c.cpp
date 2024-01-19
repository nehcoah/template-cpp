#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> pre(n), suf(n);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (i == 1 ? 1 : a[i] - a[i - 1] <= a[i - 1] - a[i - 2] ? 1 : a[i] - a[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (i == n - 2 ? 1 : a[i + 1] - a[i] <= a[i + 2] - a[i + 1] ? 1 : a[i + 1] - a[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if (x < y) cout << pre[y - 1] - pre[x - 1] << "\n";
        else cout << suf[y - 1] - suf[x - 1] << "\n";
    }
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
