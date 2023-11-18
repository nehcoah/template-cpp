#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 2; i++) {
        cout << i + 1 << " " << i + 2 << "\n";
    }
    int pre = -1;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        if (i == 0) {
            cout << n << " " << x << "\n";
            cout << -1 << " " << -1 << " " << -1 << "\n";
        } else {
            if (pre == x) cout << -1 << " " << -1 << " " << -1 << "\n";
            else cout << n << " " << pre << " " << x << "\n";
        }
        pre = x;
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


