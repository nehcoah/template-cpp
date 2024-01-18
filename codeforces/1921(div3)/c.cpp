#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> m(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ll cost = min((m[i] - cur) * a, b);
        f -= cost;
        if (f <= 0) {
            cout << "NO\n";
            return;
        }
        cur = m[i];
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
