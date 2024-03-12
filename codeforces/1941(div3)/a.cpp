#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n), c(m);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i] + c[j] <= k) ans += 1;
        }
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
