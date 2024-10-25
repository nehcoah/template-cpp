#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int a, b;
    cin >> a >> b;
    if (b % 2 == 0) {
        cout << (a % 2 == 0 ? "YES\n" : "NO\n");
    } else {
        cout << (a % 2 == 0 && a >= 2 ? "YES\n" : "NO\n");
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

