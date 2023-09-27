#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    ll mx = (n - k + 1 + n) * k / 2;
    ll mn = (1 + k) * k / 2;
    if (mn <= x && x <= mx) cout << "YES" << endl;
    else cout << "NO" << endl;
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
