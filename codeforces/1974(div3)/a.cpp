#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y % 2 == 0) {
        int cnt = y / 2 * 7;
        cout << y / 2 + (max(0, x - cnt) + 14) / 15 << endl;
    } else {
        int cnt = y / 2 * 7 + 11;
        cout << y / 2 + 1 + (max(0, x - cnt) + 14) / 15 << endl;
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
