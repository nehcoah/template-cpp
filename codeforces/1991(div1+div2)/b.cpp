#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<int> a(n);
    for (int i = 0; i < n - 2; i++) {
        a[i + 1] = b[i] | b[i + 1];
    }
    a[0] = b[0], a.back() = b.back();
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] & a[i + 1]) != b[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
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

