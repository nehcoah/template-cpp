#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, P, l, t;
    cin >> n >> P >> l >> t;
    ll tasks = (n + 6) / 7;
    ll tot = t * tasks + l * ((tasks + 1) / 2);
    if (tot > P) {
        ll d = l + 2 * t;
        cout << n - (P + d - 1) / d << "\n";
    } else {
        cout << n - ((tasks + 1) / 2 + (P - tot + l - 1) / l) << "\n";
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

