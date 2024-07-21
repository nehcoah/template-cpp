#include "bits/stdc++.h"
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > 1) {
        ans += 1;
        n -= k - 1;
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
