#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x2 < y2) {
        cout << (x1 > y1 ? "NO" : "YES") << endl;
    } else {
        cout << (x1 < y1 ? "NO" : "YES") << endl;
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
