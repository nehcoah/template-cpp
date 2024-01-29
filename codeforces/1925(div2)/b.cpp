#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int x, n;
    cin >> x >> n;
    int ans = 1;
    if (n == 1) ans = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (x / i >= n) ans = max(ans, i);
            if (i >= n) ans = max(ans, x / i);
        }
    }
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
