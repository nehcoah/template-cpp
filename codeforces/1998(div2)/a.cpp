#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    vector<int> a(k), b(k);
    if (k % 2 == 1) {
        a.back() = x, b.back() = y;
    }
    for (int i = 0, p = 1; i < k - 1; i += 2, p += 1) {
        a[i] = x - p, a[i + 1] = x + p;
        b[i] = y - p, b[i + 1] = y + p;
    }
    for (int i = 0; i < k; i++) {
        cout << a[i] << " " << b[i] << "\n";
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

