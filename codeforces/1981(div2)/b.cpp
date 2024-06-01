#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    int l = max(0, n - m), r = n + m;
    int ans = 0;
    for (int i = 0; i < 31; i++) {
        if (l >> i & 1 || r >> i & 1 || r - l >= 1 << i) {
            ans |= 1 << i;
        }
    }
    cout << ans << endl;
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

