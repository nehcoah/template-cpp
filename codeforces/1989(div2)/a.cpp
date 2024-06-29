#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    y -= abs(x);
    if (y >= -abs(x) - 1) cout << "YES\n";
    else cout << "NO\n";
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
