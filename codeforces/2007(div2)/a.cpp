#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int l, r;
    cin >> l >> r;
    int odd = 0, even = 0;
    for (int i = l; i <= r; i++) {
        (i % 2 ? odd : even) += 1;
    }
    cout << min(odd / 2, even) << "\n";
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

