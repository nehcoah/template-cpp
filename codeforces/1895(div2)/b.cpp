#include "bits/stdc++.h"

using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    ranges::sort(a);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i + 1] - a[i];
    }
    for (int i = n; i < 2 * n - 1; i++) {
        ans += a[i + 1] - a[i];
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << a[n + i] << endl;
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

