// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (i * 2 - 1) * i;
    }
    cout << ans << " " << 2 * n << endl;
    for (int i = n; i; i--) {
        cout << 1 << " " << i << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << " \n"[j == n];
        }
        cout << 2 << " " << i << " ";
        for (int j = 1; j <= n; j++) {
            cout << j << " \n"[j == n];
        }
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
