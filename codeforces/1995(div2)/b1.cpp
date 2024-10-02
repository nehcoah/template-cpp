#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0, cur = 0;
    for (int r = 0, l = 0; r < n; r++) {
        cur += a[r];
        while (cur > m || a[l] + 1 < a[r]) {
            cur -= a[l++];
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
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

