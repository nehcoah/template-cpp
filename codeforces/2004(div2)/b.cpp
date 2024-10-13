#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    int ans = 0;
    for (int x = min(l, L); x <= max(r, R); x++) {
        if (l <= x && x <= r && L <= x + 1 && x + 1 <= R || l <= x + 1 && x + 1 <= r && L <= x && x <= R) {
            ans += 1;
        }
    }
    cout << max(1, ans) << "\n";
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

