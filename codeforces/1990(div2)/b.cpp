#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x -= 1, y -= 1;
    vector<int> a(n);
    for (int i = y; i <= x; i++) {
        a[i] = 1;
    }
    for (int i = y - 1; i >= 0; i--) {
        a[i] = (y - i) % 2 == 1 ? -1 : 1;
    }
    for (int i = x + 1; i < n; i++) {
        a[i] = (i - x) % 2 == 1 ? -1 : 1;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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
