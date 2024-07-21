#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;
    int c = __builtin_popcountll(n);
    if (c == 1) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        cout << c + 1 << endl;
        for (int i = 60; i >= 0; i--) {
            if (n >> i & 1) cout << (n ^ (1ll << i)) << " ";
        }
        cout << n << endl;
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
