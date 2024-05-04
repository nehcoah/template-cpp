//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int x;
    cin >> x;
    int ans = 0, y = 0;
    for (int i = 1; i < x; i++) {
        if (i + gcd(i, x) > ans) {
            ans = i + gcd(i, x);
            y = i;
        }
    }
    cout << y << endl;
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
