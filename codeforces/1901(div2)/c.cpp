#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, mx = 0, mn = 1e9;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    if (mx == mn) {
        cout << 0 << endl;
        return;
    }
    int x = int(log2(mx - mn)) + 1;
    cout << x << endl;
    if (x <= n) {
        while (mx != mn) {
            if (mn % 2 == 1 && mx % 2 == 0) {
                mx = (mx + 1) / 2;
                mn = (mn + 1) / 2;
                cout << 1 << " ";
            } else {
                mx /= 2;
                mn /= 2;
                cout << 0 << " ";
            }
        }
        cout << endl;
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


