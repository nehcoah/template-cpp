#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int a = (x + k - 1) / k;
    int b = (y + k - 1) / k;
    if (a > b) cout << 2 * a - 1 << "\n";
    else cout << 2 * b << "\n";
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

