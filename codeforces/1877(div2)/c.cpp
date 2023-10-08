#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > 3) {
        cout << 0 << endl;
        return;
    }
    if (m <= n) {
        if (k == 3) cout << 0 << endl;
        else if (k == 2) cout << m << endl;
        else cout << 1 << endl;
        return;
    }
    ll std = n + m / n - 1;
    if (k == 3) {
        cout << m - std << endl;
    } else if (k == 2) {
        cout << std << endl;
    } else {
        cout << 1 << endl;
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

