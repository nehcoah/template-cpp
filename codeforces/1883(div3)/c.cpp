#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 1e5;
    for (int x : a) {
        int b = x % k;
        if (b == 0) ans = 0;
        ans = min(ans, k - b);
    }
    if (k == 4) {
        int even = 0, odd = 0;
        for (int x : a) {
            (x % 2 == 1 ? odd : even) += 1;
        }
        if (even >= 2) ans = 0;
        if (odd >= 2) ans = min(ans, 2);
        if (odd >= 1 && even >= 1) ans = min(ans, 1);
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

