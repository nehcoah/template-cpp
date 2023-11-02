#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(q);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) cin >> x[i];

    int mask = 0, mx = 31;
    for (int y : x) {
        if (y < mx) {
            mask |= 1 << (y - 1);
            mx = y;
        }
    }

    for (int i = 0; i < n; i++) {
        int ctz = __builtin_ctz(a[i]);
        a[i] |= ((1 << ctz) - 1) & mask;
    }

    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
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

