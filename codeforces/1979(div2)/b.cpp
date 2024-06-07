#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        if ((x >> i & 1) != (y >> i & 1)) {
            ans = 1 << i;
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

