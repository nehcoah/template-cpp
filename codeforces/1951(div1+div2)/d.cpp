// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    if (n == k) {
        cout << "YES\n";
        cout << 1 << endl;
        cout << 1 << endl;
    } else {
        if (k > (n + 1) / 2) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << 2 << endl;
            cout << n - k + 1 << " " << 1 << endl;
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
