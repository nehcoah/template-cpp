#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m = 0;
    cin >> n;
    vector<int> a(n), f(n + 1, 1e9 + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x < n) a[x]++;
    }
    while (m < n && a[m]) m++;
    f[m] = 0;
    for (int i = m; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            f[j] = min(f[j], f[i] + i * (a[j] - 1) + j);
        }
    }
    cout << f[0] << endl;
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

