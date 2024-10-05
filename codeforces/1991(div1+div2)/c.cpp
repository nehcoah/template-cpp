#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != a[0] % 2) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << 30 + (a[0] % 2 == 0) << "\n";
    for (int i = 29; i >= 0; i--) {
        cout << (1 << i) << " ";
    }
    if (a[0] % 2 == 0) {
        cout << 1;
    }
    cout << "\n";
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

