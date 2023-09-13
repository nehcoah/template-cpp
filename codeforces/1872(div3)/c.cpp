#include "bits/stdc++.h"

#define endl '\n'
using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int l, r;
    cin >> l >> r;
    if (r % 2 == 0) {
        if (r != 2) cout << r / 2 << " " << r / 2 << endl;
        else cout << -1 << endl;
    } else if (l <= r - 1) {
        if (r - 1 != 2) cout << (r - 1) / 2 << " " << (r - 1) / 2 << endl;
        else cout << -1 << endl;
    } else {
        for (int x = 2; x * x <= r; x++) {
            if (r % x == 0) {
                cout << x << " " << r - x << endl;
                return;
            }
        }
        cout << -1 << endl;
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
