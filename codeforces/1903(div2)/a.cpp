#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k >= 2) cout << "YES\n";
    else {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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


