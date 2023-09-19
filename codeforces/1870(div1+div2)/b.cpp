#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) x ^= a[i];
    for (int i = 0; i < m; i++) y |= b[i];

    if (n & 1) {
        cout << x << " " << (x | y) << endl;
    } else {
        y ^= 0xffffffff;
        cout << (x & y) << " " << x << endl;
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
