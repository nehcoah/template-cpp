#include "bits/stdc++.h"

using namespace std;
using ll = long long;


void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int ans = abs(0 - y) + abs(x - y);
    ans = min(ans, abs(0 - x) + abs(x - y) + max(0, abs(y - x) - k));
    cout << ans << endl;
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

