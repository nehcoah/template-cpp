#include "bits/stdc++.h"

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

void solve() {
    ll x;
    cin >> x;

    if (x % 10 == 9) {
        cout << "NO\n";
        return;
    }
    x /= 10;
    while (x) {
        if (x < 10 && x != 1) {
            cout << "NO\n";
            return;
        }
        int t = x % 10;
        t -= 1;
        if (t == -1) {
            cout << "NO\n";
            return;
        }
        x /= 10;
    }
    cout << "YES\n";
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

