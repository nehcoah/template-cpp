#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (k) {
        int t = y - x % y;
        if (t > k) {
            x += k;
            k = 0;
        } else {
            x += t;
            while (x % y == 0) x /= y;
            k -= t;
        }
        if (x == 1) break;
    }
    k %= (y - 1);
    x += k;
    cout << x << endl;
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
