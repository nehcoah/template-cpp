#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    ll sum = 0;
    for (int i = 0; i <= x; i++) {
        ll cur = sum / (k - 1) + 1;
        sum += cur;
        if (sum > a) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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

