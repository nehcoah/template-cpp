#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;
    if (a1 > b1) {
        ans += a2 >= b2;
    } else if (a1 == b1) {
        ans += a2 > b2;
    }
    if (a1 > b2) {
        ans += a2 >= b1;
    } else if (a1 == b2) {
        ans += a2 > b1;
    }
    cout << ans * 2 << "\n";
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

