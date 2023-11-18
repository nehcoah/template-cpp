#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int idx = -1, mn = 1e9 + 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < mn) {
            mn = a[i];
            idx = i;
        }
    }
    for (int i = idx; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << idx << endl;
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


