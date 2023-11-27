#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = max(a[0], 2 * (x - a.back()));
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[i] - a[i - 1]);
    }
    cout << ans << endl;
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


