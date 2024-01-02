#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (b % a == 0) cout << b * b / a << endl;
    else cout << lcm(a, b) << endl;
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

