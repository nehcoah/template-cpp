#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ull = unsigned long long;
using u32 = unsigned;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
    } else {
        vector<int> a(n, 1);
        for (int l = n / 2 - 1, r = n / 2 + 1, c = 2; l >= 0 && r < n; l--, r++) {
            a[r] = c++;
            a[l] = c++;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
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

