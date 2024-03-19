#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;

    ll x = m / a + 1;
    ll y = m / b + 1;
    cout << x + y << endl;
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
