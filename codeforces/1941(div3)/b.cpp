#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 2; i++) {
        if (a[i] < 0) {
            cout << "NO\n";
            return;
        }
        a[i + 1] -= 2 * a[i];
        a[i + 2] -= a[i];
        a[i] = 0;
    }
    if (a[n - 1] == 0 && a[n - 2] == 0) cout << "YES\n";
    else cout << "NO\n";
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
