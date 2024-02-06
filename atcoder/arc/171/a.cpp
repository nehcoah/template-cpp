#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll x = n - a;
    if (x < 0) {
        cout << "No" << endl;
        return;
    }
    ll space = x * min(x, (n + 1) / 2);
    cout << (space >= b ? "Yes" : "No") << endl;
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
