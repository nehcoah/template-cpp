#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int x1 = 1001, x2 = -1001, y1 = 1001, y2 = -1001;
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        x1 = min(x1, x);
        x2 = max(x2, x);
        y1 = min(y1, y);
        y2 = max(y2, y);
    }
    cout << (x2 - x1) * (y2 - y1) << endl;
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
